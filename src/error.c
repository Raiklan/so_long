/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:28:42 by saich             #+#    #+#             */
/*   Updated: 2021/12/08 17:38:19 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *nature, char *all_chars)
{
	ft_putendl_fd(nature, 2);
	free(all_chars);
	exit (0);
}

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putendl_fd("map is not surrounded by walls", 2);
			free(line);
			exit (1);
		}
		i++;
	}
}

void	check_map_elements(char *all_chars)
{
	int	i;
	int	count_p;

	i = 0;
	count_p = 0;
	while (all_chars[i] != '\0')
	{
		if (all_chars[i] == 'P')
			count_p++;
		if ((all_chars[i] != '1') && (all_chars[i] != '0')
			&& (all_chars[i] != 'E') && (all_chars[i] != 'P')
			&& (all_chars[i] != 'C'))
		{
			ft_putendl_fd
			("Error\nFile contains different character than 1, 0, P, E or C", 2);
			free(all_chars);
			exit (1);
		}
		i++;
	}
	if (count_p > 1)
		ft_error("only one player should be on the map", all_chars);
}

void	deal_ret(int ret, t_game *game, char *line, char *all_chars)
{
	while (ret > 0)
	{
		game->line_number++;
		game->endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->endline] != '1')
			ft_error("Error\nWall missing in the border", all_chars);
		ft_strcat(all_chars, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && (strlen(line)
				!= (long unsigned int)game->total_line_char))
			ft_error("Error\nmap has a problem", all_chars);
		if (ret == 0)
		{
			game->line_number++;
			check_walls(line);
			ft_strcat(all_chars, line);
			free(line);
			line = 0;
		}
	}
}

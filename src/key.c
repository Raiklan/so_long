/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:25:21 by saich             #+#    #+#             */
/*   Updated: 2021/12/08 17:55:46 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_hook(t_game *game)
{
	free(game->map);
	exit(1);
}

void	is_game_finished(t_game *game)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (ft_strchr(game->map, 'E') == NULL)
	{
		if (game->nb_exit <= 1)
			if (ft_strchr(game->map, 'X') == NULL)
				exit_hook(game);
		while (game->map[i])
		{
			if (game->map[i] == 'X')
				count++;
			i++;
		}
		if (count == game->nb_exit - 1)
			exit_hook(game);
	}
}

int	reduce_window(t_game *game)
{
	draw_map(game);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (ft_strchr(game->map, 'C') == NULL)
	{
		while (ft_strchr(game->map, 'E'))
		{
			game->nb_exit++;
			*ft_strchr(game->map, 'E') = 'X';
		}
	}	
	if (keycode == 65307)
		exit_hook(game);
	if (keycode == 115)
		move_bottom(game);
	if (keycode == 119)
		move_up(game);
	if (keycode == 100)
		move_right(game);
	if (keycode == 97)
		move_left(game);
	is_game_finished(game);
	draw_map(game);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:29:47 by saich             #+#    #+#             */
/*   Updated: 2021/12/10 16:39:08 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	init_map2(t_game *game, char *all_chars)
{
	if ((ft_strchr(all_chars, 'P') == NULL)
		|| (ft_strchr(all_chars, 'E') == NULL)
		|| (ft_strchr(all_chars, 'C') == NULL))
		ft_error("Error\nMissing one player, one collectible or one exit",
			all_chars);
	if (game->line_number - 1 == game->total_line_char)
		ft_error("Error\nMap is square!", all_chars);
	check_map_elements(all_chars);
	game->map_height = (game->line_number - 1) * 40;
	game->map_width = game->total_line_char * 40;
	game->map = malloc(sizeof(char)
			* (game->total_line_char * game->line_number) + 1);
	ft_strlcpy(game->map, all_chars,
		(game->line_number * game->total_line_char));
	game->fd = close(game->fd);
	free(all_chars);
}

int	init_struc(t_game *game)
{
	game->nb_exit = 0;
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "SO_LONG");
	game->mlx.mlx_img = mlx_new_image
		(game->mlx.mlx, game->map_width, game->map_height);
	texture_init(game);
	return (1);
}

void	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments", 2);
		exit(0);
	}
	if ((ft_strlen(av[1]) < 4) || (!ft_strchr(av[1], '.')))
	{
		ft_putendl_fd("Error\nInvalid argument", 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber"))
	{
		ft_putendl_fd("Error\nFile must of the type .ber", 2);
		exit(0);
	}
}

int	init_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*all_chars;

	all_chars = (char *)malloc(sizeof(char) * 10000);
	*all_chars = 0;
	game->line_number = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		ft_error("Error\nFile cannot be opened/read", all_chars);
	line = 0;
	ret = get_next_line(game->fd, &line);
	check_walls(line);
	game->total_line_char = ft_strlen(line);
	deal_ret(ret, game, line, all_chars);
	init_map2(game, all_chars);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	check_arg(ac, av);
	init_map(&game, av[1]);
	init_struc(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 33, 1L << 5, exit_hook, &game);
	mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	mlx_loop(game.mlx.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:26:44 by saich             #+#    #+#             */
/*   Updated: 2021/12/10 16:26:11 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_bottom(t_game *game)
{
	char	*ptr;
	int		i;

	ptr = ft_strchr(game->map, 'P');
	i = -1;
	while (++i < game->total_line_char)
		++ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		ptr = ft_strchr(game->map, 'P');
		*ptr = '0';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link1.xpm");
}

void	move_up(t_game *game)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = ft_strchr(game->map, 'P');
	while (++i < game->total_line_char)
		--ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		while (--i >= 0)
			++ptr;
		*ptr = '0';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_up.xpm");
}

void	move_right(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if ((*++ptr != '1' && *ptr != 'E'))
	{
		*--ptr = '0';
		*++ptr = 'P';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_right.xpm");
}

void	move_left(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if (*--ptr != '1' && *ptr != 'E')
	{
		*++ptr = '0';
		*--ptr = 'P';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_left.xpm");
}

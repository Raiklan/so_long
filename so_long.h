/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:15:35 by saich             #+#    #+#             */
/*   Updated: 2021/12/08 17:21:45 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;

}	t_mlx;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

/*
	W 119 A 97 S 115
 	D 100
 	ESC 65307
*/
typedef struct s_game
{
	t_mlx	mlx;
	int		map_width;
	int		map_height;
	int		numb_move;
	t_img	*ground;
	t_img	*player;
	t_img	*collectible;
	t_img	*tree;
	t_img	*exit;
	char	*map;
	int		total_line_char;
	int		line_number;
	char	*player_position;
	int		nb_exit;
	int		numb;
	int		endline;
	int		fd;
	int		x;
	int		y;
}	t_game;

#endif

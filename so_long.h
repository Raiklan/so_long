/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:15:35 by saich             #+#    #+#             */
/*   Updated: 2021/11/29 15:21:59 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "mlx.h"
#include <unistd.h>

/*
	W 119 A 97 S 115
 	D 100
 	ESC 65307
*/
typedef struct	s_img
{
	void	*mlx_ptr;
	char	*addr;
	int		height;
	int		width;
	int		endian;
	int		size_line;
	int		bpp;
}				t_img;

typedef struct	s_texture
{
	t_img	guts;
	t_img	behelit;
	t_img	eclipse;
	t_img	wall;
	t_img	plan;
}				t_texture;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_mlx;

typedef struct	s_key
{
	int		W;
	int		A;
	int		S;
	int		D;
	int		ESC;
	int		nbr_count;
}				t_key;

typedef struct	s_pos
{
	int		init;
	int		X;
	int		Y;
}				t_pos;

typedef struct	s_every
{
	t_img img;
	t_mlx mlx;
	t_texture texture;
	t_key key;
}				t_every;




#endif

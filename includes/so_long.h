/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:15:35 by saich             #+#    #+#             */
/*   Updated: 2021/12/12 05:36:07 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>
# include "../includes/get_next_line.h"

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

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			texture_init(t_game *game);
void			texture_load(t_game *game, t_img **img, char *path);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			move_up(t_game *game);
void			move_bottom(t_game *game);
int				exit_hook(t_game *game);
void			is_game_finished(t_game *game);
int				reduce_window(t_game *game);
int				key_hook(int keycode, t_game *game);
void			ft_error(char *nature, char *all_chars);
void			ft_error_line(char *nature, char *all_chars, char *line);
void			check_walls(char *line);
void			check_map_elements(char *all_chars);
void			deal_ret(int ret, t_game *game, char *line, char *all_chars);
void			draw_square(t_game *game, t_img *img, int x, int y);
void			check_for_elements(t_game *game, int x, int y, int z);
void			draw_map(t_game *game);
void			init_map2(t_game *game, char *whole_chars);
int				init_struc(t_game *game);
void			check_arg(int ac, char **av);
int				init_map(t_game *game, char *map_name);

#endif

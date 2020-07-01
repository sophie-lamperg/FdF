/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:11:03 by gyesenia          #+#    #+#             */
/*   Updated: 2020/02/13 13:25:37 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# define WIDHT 1920
# define HEIGHT 1080
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct		s_coords
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coords;

typedef struct		s_delta
{
	int				deltax;
	int				deltay;
}					t_delta;

typedef struct		s_convert
{
	int				max_z;
	int				z_min;
	int				z_point;
	int				fst_spl_count;
	int				spl_atoi_count;
	int				x_max;
	int				y_max;
	int				num_point;
	char			**spl_new_line;
	int				*z_points;
	char			**spl_wspace;
	int				zoom;
	int				shift_x;
	int				shift_y;
	int				is_iso;
	void			*mlx;
	void			*win;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_div;
}					t_convert;

typedef struct		s_errors
{
	int				error;
	int				error2;
}					t_errors;

int					ft_abs(int a);
char				*ft_reader(char *arr);
int					count_y(char *c_y);
int					count_x(char *c_x);
void				prepare_data(t_convert *con, char *str);
int					deal_key(int key, void *param);
int					convert_int(t_convert *con, char *str);
void				iso(int *x, int *y, int z);
void				bresenham(t_coords a, t_coords b, t_convert *con);
void				draw(t_convert *con);
t_coords			prepare_cord(t_coords point, t_convert *con);
void				fill_tab(t_convert *con);
void				rotate_x(int *y, int *z, double alpha);
void				rotate_y(int *x, int *z, double beta);
void				rotate_z(int *x, int *y, double gamma);
void				rotate(int key, t_convert *con);
void				control_keys(t_convert *con);
void				move(int key, t_convert *con);
void				check_abroad(t_convert *con);
int					close_win(void *param);
void				switch_proj(t_convert *con);
void				zomming(int key, t_convert *con);
int					ft_error(char *res);
void				check_map(char *str, int max_x);
int					z_max(t_convert *con);
int					z_min(t_convert *con);
t_coords			set_coords(int x, int y, t_convert *con);
int					color(t_coords cur, t_coords a, t_coords b, t_delta delta);
int					get_default_color(int z, t_convert *con);
#endif

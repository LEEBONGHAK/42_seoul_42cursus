/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:32:50 by bolee             #+#    #+#             */
/*   Updated: 2022/07/04 15:32:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* standard header for open(), perror(), and math funcs */
# include <fcntl.h>
# include <stdio.h>

# define _USE_MATH_DEFINES
# include <math.h>

/* MiniLibX */
# include <mlx.h>

/* my header */
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"

/* color */
# define WHITE 0x00FFFFFF

/* union about color infomation */
typedef union u_argb
{
	struct
	{
		char	a;
		char	r;
		char	g;
		char	b;
	};
	char	data[4];
	int		argb;
}	t_argb;

/* structure about mlx instance and window instance */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

/* structure about image for drawing to window */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/* structure about 3D coordinate */
typedef struct s_3d
{
	double	x;
	double	y;
	double	z;
	t_argb	color;
}	t_3d;

/* structure about 2D coordinate */
typedef struct s_2d
{
	int		x;
	int		y;
	t_argb	color;
}	t_2d;

/* structure for using bresenham's line algorithm */
typedef struct s_data
{
	int		s_x;
	int		s_y;
	int		f_x;
	int		f_y;
	int		width;
	int		height;
	int		dx;
	int		dy;
	t_argb	color;
	char	da;
	char	dr;
	char	dg;
	char	db;
}	t_data;

/* structure about screen size and position */
typedef struct s_scr
{
	int	width;
	int	height;
	int	pos_x;
	int	pos_y;
}	t_scr;

/* structure for idexs */
typedef struct s_idx
{
	int	i;
	int	j;
}	t_idx;

/* in fdf_utils.c */
void	err_exit(char *str);
void	perr_exit(char *str);
void	free_double_arr(void **arr);
int		double_arr_size(void **arr);
int		fdf_strchr(const char *s, int c);

/* in struct_init.c */
void	init_t_3d(t_3d *tmp, double x, double y, double z);
void	init_t_data_v(t_data *data, t_2d **cdn_2, t_idx idx, t_scr scr);
void	init_t_data_h(t_data *data, t_2d **cdn_2, t_idx idx, t_scr scr);
t_scr	init_screen(t_2d **cdn_2);

/* in get_cdn_3.c */
t_3d	**get_cdn_3(int fd);

/* in get_cdn_2.c */
t_2d	**get_cdn_2(t_3d **cdn_3, int scale);

/* in draw_win.c */
void	draw_win(t_2d **cdn_2, t_mlx *mlx, t_scr scr);

/* in drew_win_utils.c */
int		min_x(t_2d **cdn_2);
int		win_x(t_2d **cdn_2);
int		win_y(t_2d **cdn_2);
int		min_y(t_2d **cdn_2);

/* in size_control.c */
t_2d	**take_cdn_2(t_3d **cdn_3, char *map);

#endif

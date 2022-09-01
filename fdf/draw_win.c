/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:29:51 by bolee             #+#    #+#             */
/*   Updated: 2022/07/21 17:27:00 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	draw_line_below_one(t_img *img, t_data data)
{
	int	f;

	f = 2 * data.height - data.width;
	while (data.s_x != data.f_x)
	{
		my_mlx_pixel_put(img, data.s_x, data.s_y, data.color.argb);
		if (f < 0)
			f += 2 * data.height;
		else
		{
			data.s_y += data.dy;
			f += 2 * data.height - 2 * data.width;
		}
		data.s_x += data.dx;
		data.color.a += data.da;
		data.color.r += data.dr;
		data.color.g += data.dg;
		data.color.b += data.db;
	}
}

static void	draw_line_geater_one(t_img *img, t_data data)
{
	int	f;

	f = 2 * data.width - data.height;
	while (data.s_y != data.f_y)
	{
		my_mlx_pixel_put(img, data.s_x, data.s_y, data.color.argb);
		if (f < 0)
			f += 2 * data.width;
		else
		{
			data.s_x += data.dx;
			f += 2 * data.width - 2 * data.height;
		}
		data.s_y += data.dy;
		data.color.a += data.da;
		data.color.r += data.dr;
		data.color.g += data.dg;
		data.color.b += data.db;
	}
}

static void	draw_img(t_img *img, t_2d **cdn_2, t_idx idx, t_scr scr)
{
	t_data	data;

	if (!(cdn_2[idx.i][idx.j + 1].x == 2147483647 \
		&& cdn_2[idx.i][idx.j + 1].y == 2147483647))
	{
		init_t_data_v(&data, cdn_2, idx, scr);
		if (data.width > data.height)
			draw_line_below_one(img, data);
		else
			draw_line_geater_one(img, data);
	}
	if (cdn_2[idx.i + 1])
	{
		init_t_data_h(&data, cdn_2, idx, scr);
		if (data.width > data.height)
			draw_line_below_one(img, data);
		else
			draw_line_geater_one(img, data);
	}
}

void	draw_win(t_2d **cdn_2, t_mlx *mlx, t_scr scr)
{
	t_idx	idx;
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, scr.width, scr.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	idx.i = 0;
	while (cdn_2[idx.i])
	{
		idx.j = 0;
		while (!(cdn_2[idx.i][idx.j].x == 2147483647 \
			&& cdn_2[idx.i][idx.j].y == 2147483647))
		{
			draw_img(&img, cdn_2, idx, scr);
			idx.j++;
		}
		idx.i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
}

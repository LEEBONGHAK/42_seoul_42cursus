/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:55:12 by bolee             #+#    #+#             */
/*   Updated: 2022/08/13 15:55:13 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_t_3d(t_3d *tmp, double x, double y, double z)
{
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
}

static void	set_color(t_data *data, t_argb s_color, t_argb f_color)
{
	int	length;

	length = (int) round(sqrt(pow((data->f_x - data->s_x), 2) \
						+ pow((data->f_y - data->s_y), 2)));
	if (length)
	{
		data->da = (f_color.a - s_color.a) / length;
		data->dr = (f_color.r - s_color.r) / length;
		data->dg = (f_color.g - s_color.g) / length;
		data->db = (f_color.b - s_color.b) / length;
	}
	else
	{
		data->da = 0;
		data->dr = 0;
		data->dg = 0;
		data->db = 0;
	}
}

void	init_t_data_v(t_data *data, t_2d **cdn_2, t_idx idx, t_scr scr)
{
	data->s_x = cdn_2[idx.i][idx.j].x + scr.pos_x;
	data->s_y = cdn_2[idx.i][idx.j].y + scr.pos_y;
	data->f_x = cdn_2[idx.i][idx.j + 1].x + scr.pos_x;
	data->f_y = cdn_2[idx.i][idx.j + 1].y + scr.pos_y;
	data->width = abs(cdn_2[idx.i][idx.j + 1].x - cdn_2[idx.i][idx.j].x);
	data->height = abs(cdn_2[idx.i][idx.j + 1].y - cdn_2[idx.i][idx.j].y);
	data->dx = 1;
	if (cdn_2[idx.i][idx.j + 1].x < cdn_2[idx.i][idx.j].x)
		data->dx = -1;
	data->dy = 1;
	if (cdn_2[idx.i][idx.j + 1].y < cdn_2[idx.i][idx.j].y)
		data->dy = -1;
	data->color.argb = cdn_2[idx.i][idx.j].color.argb;
	set_color(data, cdn_2[idx.i][idx.j].color, cdn_2[idx.i][idx.j + 1].color);
}

void	init_t_data_h(t_data *data, t_2d **cdn_2, t_idx idx, t_scr scr)
{
	data->s_x = cdn_2[idx.i][idx.j].x + scr.pos_x;
	data->s_y = cdn_2[idx.i][idx.j].y + scr.pos_y;
	data->f_x = cdn_2[idx.i + 1][idx.j].x + scr.pos_x;
	data->f_y = cdn_2[idx.i + 1][idx.j].y + scr.pos_y;
	data->width = abs(cdn_2[idx.i + 1][idx.j].x - cdn_2[idx.i][idx.j].x);
	data->height = abs(cdn_2[idx.i + 1][idx.j].y - cdn_2[idx.i][idx.j].y);
	data->dx = 1;
	if (cdn_2[idx.i + 1][idx.j].x < cdn_2[idx.i][idx.j].x)
		data->dx = -1;
	data->dy = 1;
	if (cdn_2[idx.i + 1][idx.j].y < cdn_2[idx.i][idx.j].y)
		data->dy = -1;
	data->color.argb = cdn_2[idx.i][idx.j].color.argb;
	set_color(data, cdn_2[idx.i][idx.j].color, cdn_2[idx.i + 1][idx.j].color);
}

t_scr	init_screen(t_2d **cdn_2)
{
	t_scr	tmp;

	tmp.width = win_x(cdn_2) + 100;
	tmp.height = win_y(cdn_2) + 100;
	tmp.pos_x = -1 * min_x(cdn_2) + 50;
	tmp.pos_y = -1 * min_y(cdn_2) + 50;
	return (tmp);
}

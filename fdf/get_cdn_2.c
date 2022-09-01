/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cdn_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:58:24 by bolee             #+#    #+#             */
/*   Updated: 2022/07/21 16:58:26 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	cal_x(t_3d **cdn_3, int i, int j, int scale)
{
	return ((int) round((cos(M_PI / 4) * cdn_3[i][j].x \
				- sin(M_PI / 4) * cdn_3[i][j].y) * scale));
}

static int	cal_y(t_3d **cdn_3, int i, int j, int scale)
{
	return ((int) round((cos(-1 * asin(tan(M_PI / 6))) \
				* sin(M_PI / 4) * cdn_3[i][j].x \
				+ cos(-1 * asin(tan(M_PI / 6))) * cos(M_PI / 4) * cdn_3[i][j].y \
				+ sin(-1 * asin(tan(M_PI / 6))) * cdn_3[i][j].z) * scale));
}

static void	make_cdn_2(t_2d **cdn_2, t_3d **cdn_3, int size, int scale)
{
	int	i;
	int	j;

	i = 0;
	while (cdn_3[i])
	{
		j = 0;
		cdn_2[i] = (t_2d *)malloc(sizeof(t_2d) * (size + 1));
		if (!cdn_2[i])
			err_exit("\033[0;31m[ERROR] malloc() error\033[0m\n");
		while (!(cdn_3[i][j].x == -1 && cdn_3[i][j].y == -1 \
			&& cdn_3[i][j].z == -1))
		{
			cdn_2[i][j].x = cal_x(cdn_3, i, j, scale);
			cdn_2[i][j].y = cal_y(cdn_3, i, j, scale);
			cdn_2[i][j].color.argb = cdn_3[i][j].color.argb;
			j++;
		}
		cdn_2[i][j].x = 2147483647;
		cdn_2[i][j].y = 2147483647;
		i++;
	}
}

t_2d	**get_cdn_2(t_3d **cdn_3, int scale)
{
	int		size;
	t_2d	**cdn_2;

	size = double_arr_size((void **)cdn_3);
	cdn_2 = (t_2d **)malloc(sizeof(t_2d *) * (size + 1));
	if (!cdn_2)
		err_exit("\033[0;31m[ERROR] malloc() error\033[0m\n");
	cdn_2[size] = NULL;
	size = 0;
	while (!(cdn_3[0][size].x == -1 && cdn_3[0][size].y == -1 \
		&& cdn_3[0][size].z == -1))
		size++;
	make_cdn_2(cdn_2, cdn_3, size, scale);
	return (cdn_2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:02:43 by bolee             #+#    #+#             */
/*   Updated: 2022/08/13 20:13:30 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_x(t_2d **cdn_2)
{
	int	i;
	int	j;
	int	min_x;

	min_x = 2147483647;
	i = 0;
	while (cdn_2[i])
	{
		j = 0;
		while (!(cdn_2[i][j].x == 2147483647 && cdn_2[i][j].y == 2147483647))
		{
			if (cdn_2[i][j].x < min_x)
				min_x = cdn_2[i][j].x;
			j++;
		}
		i++;
	}
	return (min_x);
}

int	win_x(t_2d **cdn_2)
{
	int	i;
	int	j;
	int	min_x;
	int	max_x;

	min_x = 2147483647;
	max_x = -2147483648;
	i = 0;
	while (cdn_2[i])
	{
		j = 0;
		while (!(cdn_2[i][j].x == 2147483647 && cdn_2[i][j].y == 2147483647))
		{
			if (cdn_2[i][j].x > max_x)
				max_x = cdn_2[i][j].x;
			if (cdn_2[i][j].x < min_x)
				min_x = cdn_2[i][j].x;
			j++;
		}
		i++;
	}
	return (max_x - min_x);
}

int	win_y(t_2d **cdn_2)
{
	int	i;
	int	j;
	int	min_y;
	int	max_y;

	min_y = 2147483647;
	max_y = -2147483648;
	i = 0;
	while (cdn_2[i])
	{
		j = 0;
		while (!(cdn_2[i][j].x == 2147483647 && cdn_2[i][j].y == 2147483647))
		{
			if (cdn_2[i][j].y > max_y)
				max_y = cdn_2[i][j].y;
			if (cdn_2[i][j].y < min_y)
				min_y = cdn_2[i][j].y;
			j++;
		}
		i++;
	}
	return (max_y - min_y);
}

int	min_y(t_2d **cdn_2)
{
	int	i;
	int	j;
	int	min_y;

	min_y = 2147483647;
	i = 0;
	while (cdn_2[i])
	{
		j = 0;
		while (!(cdn_2[i][j].x == 2147483647 && cdn_2[i][j].y == 2147483647))
		{
			if (cdn_2[i][j].y < min_y)
				min_y = cdn_2[i][j].y;
			j++;
		}
		i++;
	}
	return (min_y);
}

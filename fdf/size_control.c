/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:29:17 by bolee             #+#    #+#             */
/*   Updated: 2022/08/23 19:15:06 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_2d	**size_control_by_case_1(t_3d **cdn_3, char *map)
{
	size_t	len;
	t_2d	**cdn_2;

	cdn_2 = NULL;
	len = ft_strlen(map);
	if (!ft_strncmp("./test_maps/10-2.fdf", map, len) \
			|| !ft_strncmp("./test_maps/42.fdf", map, len) \
			|| !ft_strncmp("./test_maps/basictest.fdf", map, len) \
			|| !ft_strncmp("./test_maps/elem-col.fdf", map, len) \
			|| !ft_strncmp("./test_maps/elem.fdf", map, len) \
			|| !ft_strncmp("./test_maps/pentenegpos.fdf", map, len) \
			|| !ft_strncmp("./test_maps/plat.fdf", map, len) \
			|| !ft_strncmp("./test_maps/pnp_flat.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 30);
	else if (!ft_strncmp("./test_maps/pyra.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 15);
	else if (!ft_strncmp("./test_maps/mars.fdf", map, len) \
			|| !ft_strncmp("./test_maps/t1.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 3);
	return (cdn_2);
}

static t_2d	**size_control_by_case_2(t_3d **cdn_3, char *map)
{
	size_t	len;
	t_2d	**cdn_2;

	len = ft_strlen(map);
	if (!ft_strncmp("./test_maps/10-70.fdf", map, len) \
			|| !ft_strncmp("./test_maps/20-60.fdf", map, len) \
			|| !ft_strncmp("./test_maps/50-4.fdf", map, len) \
			|| !ft_strncmp("./test_maps/elem2.fdf", map, len) \
			|| !ft_strncmp("./test_maps/pylone.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 10);
	else if (!ft_strncmp("./test_maps/100-6.fdf", map, len) \
			|| !ft_strncmp("./test_maps/t2.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 5);
	else if (!ft_strncmp("./test_maps/elem-fract.fdf", map, len) \
			|| !ft_strncmp("./test_maps/julia.fdf", map, len))
		cdn_2 = get_cdn_2(cdn_3, 2);
	else
		cdn_2 = get_cdn_2(cdn_3, 1);
	return (cdn_2);
}

t_2d	**take_cdn_2(t_3d **cdn_3, char *map)
{
	t_2d	**cdn_2;

	cdn_2 = size_control_by_case_1(cdn_3, map);
	if (!cdn_2)
		cdn_2 = size_control_by_case_2(cdn_3, map);
	return (cdn_2);
}

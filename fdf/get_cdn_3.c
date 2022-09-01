/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cdn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:19:36 by bolee             #+#    #+#             */
/*   Updated: 2022/07/06 14:19:37 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**fdf_realloc(char	**ptr, int size)
{
	int		i;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		err_exit("\033[0;31m[ERROR] fdf_realloc() error\033[0m\n");
	res[size] = NULL;
	if (!size)
		return (res);
	i = 0;
	if (ptr)
	{
		while (i < size)
		{
			res[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (res);
}

static char	**get_content(int fd)
{
	int		size;
	char	*tmp;
	char	**content;

	content = NULL;
	size = 0;
	while (1)
	{
		content = fdf_realloc(content, size);
		tmp = get_next_line(fd);
		if (!tmp || tmp[0] == '\n')
			break ;
		content[size] = tmp;
		size++;
	}
	return (content);
}

static void	set_color(t_3d *tmp, char *str)
{
	int		i;
	int		size;
	int		res;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	size = 0;
	res = 0;
	while (str[i] != ',')
		i++;
	i += 3;
	while (str[i + size])
		size++;
	while (str[i])
		res += (int) pow(16, size-- - 1) * \
			fdf_strchr(base, ft_tolower(str[i++]));
	(tmp->color).argb = res;
}

static t_3d	*make_cdn(char	*content, int y, int i)
{
	int		size;
	char	**split;
	t_3d	*arr;
	t_3d	tmp;

	split = ft_split(content, ' ');
	if (!split)
		err_exit("\033[0;31m[ERROR] ft_split() error\033[0m\n");
	size = double_arr_size((void **) split);
	arr = (t_3d *)malloc(sizeof(t_3d) * (size + 1));
	if (!arr)
		err_exit("\033[0;31m[ERROR] malloc() error\033[0m\n");
	init_t_3d(&tmp, -1, -1, -1);
	arr[size] = tmp;
	while (i < size)
	{
		init_t_3d(&tmp, i, y, ft_atoi(split[i]));
		tmp.color.argb = WHITE;
		if (fdf_strchr(split[i], ','))
			set_color(&tmp, split[i]);
		arr[i++] = tmp;
	}
	free_double_arr((void **) split);
	return (arr);
}

t_3d	**get_cdn_3(int fd)
{
	int		i;
	int		size;
	char	**content;
	t_3d	**cdn;

	content = get_content(fd);
	if (!content)
		err_exit("\033[0;31m[ERROR] ft_split() error\033[0m\n");
	size = double_arr_size((void **)content);
	cdn = (t_3d **)malloc(sizeof(t_3d *) * (size + 1));
	if (!cdn)
		err_exit("\033[0;31m[ERROR] malloc() error\033[0m\n");
	cdn[size] = NULL;
	i = 0;
	while (content[i])
	{
		cdn[i] = make_cdn(content[i], i, 0);
		i++;
	}
	free_double_arr((void **)content);
	return (cdn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:40:48 by bolee             #+#    #+#             */
/*   Updated: 2022/07/04 15:40:49 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	exit(1);
}

void	perr_exit(char *str)
{
	perror(str);
	exit(1);
}

void	free_double_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	double_arr_size(void **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

int	fdf_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*u_s;
	unsigned char	u_c;

	i = 0;
	u_s = (unsigned char *) s;
	u_c = (unsigned char) c;
	while (u_s[i] && u_s[i] != u_c)
		i++;
	if (u_s[i] == u_c)
		return (i);
	return (0);
}

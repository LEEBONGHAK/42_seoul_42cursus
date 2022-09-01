/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:24:46 by bolee             #+#    #+#             */
/*   Updated: 2022/03/24 19:55:21 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	haveconversions(const char *str)
{
	int		i;
	int		j;
	char	*conversions;

	i = 0;
	conversions = "cspdiuxX%";
	while (str[i])
	{
		j = 0;
		while (str[i] == '%' && conversions[j])
		{
			if (conversions[j] == str[i + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	isconversions(const char c)
{
	int		i;
	char	*conversions;

	i = 0;
	conversions = "cspdiuxX%";
	while (conversions[i])
	{
		if (conversions[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	print_str(const char *res)
{
	int	size;

	size = pf_strlen(res);
	if (write(1, res, size) == -1)
		return (-1);
	return (size);
}

void	pf_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
}

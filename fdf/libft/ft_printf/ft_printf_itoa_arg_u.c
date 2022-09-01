/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf_itoa.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: bolee <bolee@student.42seoul.kr>   +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2022/03/25 13:44:13 by bolee #+##+# */
/*   Updated: 2022/03/25 13:44:14 by bolee###   ########.fr   */
/**/
/* ************************************************************************** */

#include "ft_printf.h"

static long	find_size(long n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static long	find_for_div(long n)
{
	long	i;
	long	size;
	long	for_div;

	i = 1;
	for_div = 1;
	size = find_size(n);
	while (i < size)
	{
		for_div *= 10;
		i++;
	}
	return (for_div);
}

static void	put_in_res(char *res, long n)
{
	int		i;
	long	for_div;

	i = 0;
	for_div = find_for_div(n);
	while (for_div != 0)
	{
		res[i] = 48 + n / for_div;
		n %= for_div;
		for_div /= 10;
		i++;
	}
	res[i] = '\0';
}

char	*pf_itoa(int n)
{
	char	*res;
	long	size;
	long	num;

	num = (long) n;
	if (n < 0)
	{
		num *= -1;
		size = find_size(num);
		res = (char *)malloc((size + 2) * sizeof(char));
		if (!res)
			return (0);
		res[0] = '-';
		put_in_res(res + 1, num);
	}
	else
	{
		size = find_size(num);
		res = (char *)malloc((size + 1) * sizeof(char));
		if (!res)
			return (0);
		put_in_res(res, num);
	}
	return (res);
}

char	*arg_u(unsigned int u)
{
	char	*res;
	long	size;
	long	num;

	num = (long) u;
	size = find_size(num);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	put_in_res(res, num);
	return (res);
}

/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf_arg_xX.c :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: bolee <bolee@student.42seoul.kr>   +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2022/03/25 14:08:13 by bolee #+##+# */
/*   Updated: 2022/03/25 14:08:14 by bolee###   ########.fr   */
/**/
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_size(unsigned int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

static int	find_for_div(int size)
{
	int	i;
	int	for_div;

	i = 1;
	for_div = 1;
	while (i < size)
	{
		for_div *= 16;
		i++;
	}
	return (for_div);
}

static void	put_in_res(char *res, unsigned int n, int size, int flag)
{
	int	i;
	int	for_div;
	int	to_ascii;
	int	for_flag;

	i = 0;
	for_div = find_for_div(size);
	for_flag = 0;
	if (flag)
		for_flag = 32;
	while (for_div != 0)
	{
		to_ascii = 48;
		if (n / for_div >= 10)
			to_ascii = 87 - for_flag;
		res[i] = to_ascii + n / for_div;
		n %= for_div;
		for_div /= 16;
		i++;
	}
	res[i] = '\0';
}

char	*arg_x(long x, int flag)
{
	unsigned int	num;
	char			*res;
	long			size;

	num = (unsigned int) x;
	size = find_size(num);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	put_in_res(res, num, size, flag);
	return (res);
}

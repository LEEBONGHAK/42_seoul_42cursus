/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf_arg_p.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: bolee <bolee@student.42seoul.kr>   +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2022/03/25 13:50:45 by bolee #+##+# */
/*   Updated: 2022/03/25 13:50:47 by bolee###   ########.fr   */
/**/
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long	find_size(unsigned long n)
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

static unsigned long	find_for_div(unsigned long size)
{
	unsigned long	i;
	unsigned long	for_div;

	i = 1;
	for_div = 1;
	while (i < size)
	{
		for_div *= 16;
		i++;
	}
	return (for_div);
}

static void	put_in_res(char *res, unsigned long n, unsigned long size)
{
	int				i;
	unsigned long	for_div;
	int				to_ascii;

	i = 0;
	for_div = find_for_div(size);
	while (for_div != 0)
	{
		to_ascii = 48;
		if (n / for_div >= 10)
			to_ascii = 87;
		res[i] = to_ascii + n / for_div;
		n %= for_div;
		for_div /= 16;
		i++;
	}
	res[i] = '\0';
}

char	*arg_p(void *p)
{
	char			*res;
	unsigned long	size;
	unsigned long	num;

	num = (unsigned long) p;
	size = find_size(num);
	res = (char *)malloc((size + 3) * sizeof(char));
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = 'x';
	put_in_res(res + 2, num, size);
	return (res);
}

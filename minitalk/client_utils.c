/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:35:14 by bolee             #+#    #+#             */
/*   Updated: 2022/06/22 21:35:15 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(unsigned char c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_atol(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			err_exit("[ERROR] Invalid Input: Please check input.");
		res = res * 10 + *str - 48;
		str++;
	}
	return (sign * res);
}

int	get_input_pid(char *pid)
{
	long	*tmp;
	int		res;

	tmp = (long *)malloc(sizeof(long));
	if (!tmp)
		err_exit("[ERROR] Invalid Input: Please check input.");
	*tmp = ft_atol(pid);
	if (*tmp > 9999998 || *tmp < 100)
		err_exit("[ERROR] Invalid Input: Please check input.");
	res = (int) *tmp;
	free(tmp);
	return (res);
}

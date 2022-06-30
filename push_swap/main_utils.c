/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:15:48 by bolee             #+#    #+#             */
/*   Updated: 2022/06/18 18:15:49 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_control(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

long	ft_atol(const char *str)
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
			err_control();
		res = res * 10 + *str - 48;
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			err_control();
		str++;
	}
	return (sign * res);
}

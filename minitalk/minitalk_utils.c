/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:43:34 by bolee             #+#    #+#             */
/*   Updated: 2022/06/23 20:43:35 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	return (len);
}

void	err_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}

void	success_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	exec_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		err_exit("[ERROR] kill() error");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:54:41 by bolee             #+#    #+#             */
/*   Updated: 2022/06/23 15:20:43 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	long	server_pid;
	char	*msg;

	if (argc != 3)
		err_exit("[ERROR] Invalid Input: Please check input.");
	ft_printf("CLIENT PID: %d\n", getpid());
	server_pid = get_input_pid(argv[0]);
	msg = argv[1];
	return (0);
}

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

t_info	g_info;

static void	send_msg(int signo)
{
	static int	idx;
	static int	cnt;

	usleep(50);
	cnt++;
	if (signo == SIGUSR2)
		success_exit("[SUCCESS] Message sent successfully");
	if (g_info.msg[idx] & (1 << (8 - cnt)))
		exec_kill(g_info.server_pid, SIGUSR1);
	else
		exec_kill(g_info.server_pid, SIGUSR2);
	if (cnt == 8)
	{
		idx++;
		cnt = 0;
	}
}

static void	connected(int signo)
{
	usleep(50);
	if (signo == SIGUSR2)
		err_exit("[ERROR] Connection failure");
	ft_printf("[SUCCESS] Connected to the server (PID: %d)\n", \
		g_info.server_pid);
	if (signal(SIGUSR1, send_msg) == SIG_ERR \
		|| signal(SIGUSR2, send_msg) == SIG_ERR)
		err_exit("[ERROR] signal() error");
	send_msg(signo);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		err_exit("[ERROR] Invalid Input: Please check input.");
	ft_printf("CLIENT PID: %d\n", getpid());
	g_info.server_pid = get_input_pid(argv[1]);
	g_info.msg = argv[2];
	if (signal(SIGUSR1, connected) == SIG_ERR \
		|| signal(SIGUSR2, connected) == SIG_ERR)
		err_exit("[ERROR] signal() error");
	exec_kill(g_info.server_pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}

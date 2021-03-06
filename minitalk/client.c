/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:54:41 by bolee             #+#    #+#             */
/*   Updated: 2022/06/30 19:45:06 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	stop_sig(int signo)
{
	if (signo == SIGUSR2)
		exit(0);
}

static void	send_msg(pid_t pid, char *msg)
{
	int	idx;
	int	cnt;
	int	len;

	idx = 0;
	cnt = 0;
	len = ft_strlen(msg);
	while (idx <= len)
	{
		cnt++;
		if (msg[idx] & (1 << (8 - cnt)))
			exec_kill(pid, SIGUSR1);
		else
			exec_kill(pid, SIGUSR2);
		if (cnt == 8)
		{
			idx++;
			cnt = 0;
		}
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		err_exit("[ERROR] Invalid Input: Please check input.");
	ft_printf("CLIENT PID: %d\n", getpid());
	server_pid = get_input_pid(argv[1]);
	if (signal(SIGUSR2, stop_sig) == SIG_ERR)
		err_exit("[ERROR] signal() error");
	send_msg(server_pid, argv[2]);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:54:44 by bolee             #+#    #+#             */
/*   Updated: 2022/06/30 19:45:00 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_msg(unsigned char *msg, int *cnt, pid_t client_pid)
{
	if (*msg == '\0')
	{
		ft_printf("\nSERVER PID: %d\n", getpid());
		*msg = 0;
		*cnt = 0;
		exec_kill(client_pid, SIGUSR2);
	}
	ft_putchar(*msg);
	*cnt = 0;
}

static void	recv_sig(int sig, siginfo_t *sip, void *ucp)
{
	static int				cnt;
	static unsigned char	msg;
	static pid_t			client_pid;

	ucp = NULL;
	if (!cnt && !msg)
		client_pid = sip->si_pid;
	if (sip->si_pid == client_pid || sip->si_pid == 0)
	{
		cnt++;
		if (sig == SIGUSR1)
			msg |= 1 << (8 - cnt);
		else if (sig == SIGUSR2)
			msg &= ~(1 << (8 - cnt));
		if (cnt == 8)
			write_msg(&msg, &cnt, client_pid);
	}
	else
		exec_kill(sip->si_pid, SIGUSR2);
}

int	main(void)
{
	t_sigact	sigact;

	ft_printf("SERVER PID: %d\n", getpid());
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = recv_sig;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1 \
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		err_exit("[ERROR] sigaction() error");
	while (1)
		pause();
	return (0);
}

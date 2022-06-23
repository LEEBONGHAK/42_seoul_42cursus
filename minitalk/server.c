/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:54:44 by bolee             #+#    #+#             */
/*   Updated: 2022/06/22 20:54:45 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void	recv_msg(int sig, siginfo_t *sip, ucontext_t *ucp)
// {
// 	static unsigned char msg;

// 	if (sig == SIGUSR1)
// 	{

// 	}
// 	else if (sig == SIGUSR2)
// 	{

// 	}
// 	else
// 	{

// 	}
// }

static void	print_client_pid(int sig, siginfo_t *sip, ucontext_t *ucp)
{
	t_sigact	sigact;

	(int) sig;
	(ucontext_t *) ucp;
	ft_printf("Client connected (PID: %d)\n", sip->si_pid);
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigact.sa_sigaction = recv_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1 \
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		err_exit("[ERRPR] sigaction() error");
}

int	main(void)
{
	t_sigact	sigact;

	ft_printf("SERVER PID: %d\n", getpid());
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = print_client_pid;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		err_exit("[ERRPR] sigaction() error");
	while (1)
		pause();
	return (0);
}

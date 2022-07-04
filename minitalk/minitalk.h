/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:51:19 by bolee             #+#    #+#             */
/*   Updated: 2022/06/23 15:23:52 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* standard header files */
# include <unistd.h>
# include <signal.h>

/* my header file */
# include "./ft_printf/ft_printf.h"

/* sigaction structure */
typedef struct sigaction	t_sigact;

/* structure for client */
typedef struct s_info
{
	int		server_pid;
	char	*msg;
}	t_info;

/* in client_utils.c */
int		get_input_pid(char *pid);

/* in minitalk_utils.c */
int		ft_strlen(char *msg);
void	err_exit(char *str);
void	success_exit(char *str);
void	exec_kill(pid_t pid, int signo);
void	ft_putchar(char c);

#endif

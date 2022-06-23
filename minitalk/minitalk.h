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
typedef struct sigaction t_sigact;

/* in client_utils.c */
long	get_input_pid(char *pid);

/* in err_controls.c */
void	err_exit(char *str);

#endif

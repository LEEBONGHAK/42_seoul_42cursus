/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:18 by bolee             #+#    #+#             */
/*   Updated: 2022/12/06 16:51:02 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				philos;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				flag;
	int				finished;
	pthread_mutex_t	*mutexs;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				cnt;
	unsigned long	started_at;
	unsigned long	ate_at;
	int				r_fork;
	int				l_fork;
	t_info			*info;
	pthread_t		thread;
}	t_philo;

/* utils */
/* ft_ functions */
size_t			ft_strlen(char *str);
long long		ft_atoi(const char *str);

/* time.c */
unsigned long	get_time(void);
void			timer(unsigned long wait_time);

/* utils.c */
int				err_return_one(char *str);
void			*err_return_null(char *str);
int				is_valid_arr(long long *arr, int n);
void			logger(t_philo *philo, int id, const char *str);

/* monitoring.c */
int				get_flag(t_philo *philo);
void			monitoring(t_philo *philo);

/* actions.c */
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

/* initialize.c */
t_philo			*init_philos(t_info *info);
t_info			*init_info(int argc, char **argv);

/* routine.c */
void			*routine(void *arg);

/* threads.c */
int				create_threads(t_philo *philo);
int				join_threads(t_philo *philo);

#endif

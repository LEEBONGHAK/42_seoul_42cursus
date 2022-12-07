/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:22 by bolee             #+#    #+#             */
/*   Updated: 2022/12/07 18:16:05 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_change_flag(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->print));
	philo->info->flag = 1;
	pthread_mutex_unlock(&(philo->info->print));
}

int	get_flag(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&(philo->info->print));
	flag = philo->info->flag;
	pthread_mutex_unlock(&(philo->info->print));
	return (flag);
}

int	_get_elapsed(t_philo *philo, int i)
{
	int	tmp;

	pthread_mutex_lock(&(philo->info->print));
	tmp = get_time() - philo[i].ate_at;
	pthread_mutex_unlock(&(philo->info->print));
	return (tmp);
}

int	_get_finished(t_philo *philo)
{
	int	finished;

	pthread_mutex_lock(&(philo->info->print));
	finished = philo->info->finished;
	pthread_mutex_unlock(&(philo->info->print));
	return (finished);
}

void	monitoring(t_philo *philo)
{
	int	i;

	while (get_flag(philo) == 0)
	{
		if (philo->info->must_eat && \
			_get_finished(philo) >= philo->info->philos)
		{
			_change_flag(philo);
			break ;
		}
		i = -1;
		while (++i < philo->info->philos)
		{
			if (_get_elapsed(philo, i) >= philo->info->die)
			{
				logger(&philo[i], philo[i].id, "is died");
				_change_flag(philo);
				break ;
			}
		}
	}
}

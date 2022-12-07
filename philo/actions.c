/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:02 by bolee             #+#    #+#             */
/*   Updated: 2022/12/07 18:21:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_eat(t_philo *philo)
{
	logger(philo, philo->id, "is eating");
	pthread_mutex_lock(&(philo->info->print));
	philo->ate_at = get_time();
	pthread_mutex_unlock(&(philo->info->print));
	timer(philo->info->eat);
	philo->cnt++;
	if (philo->cnt == philo->info->must_eat)
	{
		pthread_mutex_lock(&(philo->info->print));
		philo->info->finished++;
		pthread_mutex_unlock(&(philo->info->print));
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->mutexs[philo->r_fork]));
	logger(philo, philo->id, "has taken a fork");
	if (philo->info->philos != 1)
	{
		pthread_mutex_lock(&(philo->info->mutexs[philo->l_fork]));
		logger(philo, philo->id, "has taken a fork");
		_eat(philo);
		pthread_mutex_unlock(&(philo->info->mutexs[philo->l_fork]));
	}
	pthread_mutex_unlock(&(philo->info->mutexs[philo->r_fork]));
}

void	philo_sleep(t_philo *philo)
{
	logger(philo, philo->id, "is sleeping");
	timer(philo->info->eat);
}

void	philo_think(t_philo *philo)
{
	logger(philo, philo->id, "is thinking");
}

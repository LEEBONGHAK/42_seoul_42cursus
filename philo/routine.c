/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:25 by bolee             #+#    #+#             */
/*   Updated: 2022/12/05 13:22:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->started_at = get_time();
	pthread_mutex_lock(&(philo->info->print));
	philo->ate_at = get_time();
	pthread_mutex_unlock(&(philo->info->print));
	if (philo->id % 2)
		timer(philo->info->eat);
	while (get_flag(philo) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

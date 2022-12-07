/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:29 by bolee             #+#    #+#             */
/*   Updated: 2022/12/07 18:22:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philos)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
			return (err_return_one(\
				"Error: pthread_create(): Failed to create thread"));
		i++;
	}
	monitoring(philo);
	return (0);
}

int	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (err_return_one(\
				"Error: pthread_join(): Failed to join thread"));
		i++;
	}
	return (0);
}

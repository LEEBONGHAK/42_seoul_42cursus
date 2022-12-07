/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:12 by bolee             #+#    #+#             */
/*   Updated: 2022/12/05 13:18:15 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philos)
	{
		pthread_mutex_destroy(&info->mutexs[i]);
		i++;
	}
	free(info->mutexs);
	free(info);
}

static void	_free_philos(t_philo *philo)
{
	_free_info(philo->info);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (err_return_one(\
					"Error: Invalid Inputs: Please check parmeters."));
	info = init_info(argc, argv);
	if (!info)
		return (1);
	philos = init_philos(info);
	if (!philos)
	{
		_free_info(info);
		return (1);
	}
	if (create_threads(philos) || join_threads(philos))
	{
		_free_philos(philos);
		return (1);
	}
	_free_philos(philos);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:07 by bolee             #+#    #+#             */
/*   Updated: 2022/12/05 13:16:24 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*_set_mutex(int philos)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos);
	if (!mutex)
		return (err_return_null("Error: malloc(): Failed to allocate Memory"));
	i = 0;
	while (i < philos)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			return (err_return_null(\
				"Error: pthread_mutex_init(): Failed to initialize mutex."));
		i++;
	}
	return (mutex);
}

static t_info	*_set_info(long long *arr)
{
	t_info			*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (err_return_null("Error: malloc(): Failed to allocate Memory"));
	info->philos = arr[0];
	info->die = arr[1];
	info->eat = arr[2];
	info->sleep = arr[3];
	info->must_eat = arr[4];
	info->flag = 0;
	info->finished = 0;
	info->mutexs = _set_mutex(info->philos);
	if (!info->mutexs)
		return (NULL);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (err_return_null(\
			"Error: pthread_mutex_init(): Failed to initialize mutex."));
	return (info);
}

t_info	*init_info(int argc, char **argv)
{
	long long	arr[5];

	arr[0] = ft_atoi(argv[1]);
	arr[1] = ft_atoi(argv[2]) * 1000;
	arr[2] = ft_atoi(argv[3]) * 1000;
	arr[3] = ft_atoi(argv[4]) * 1000;
	arr[4] = 0;
	if (argc == 6)
		arr[4] = ft_atoi(argv[5]);
	if (!is_valid_arr(arr, 5))
		return (NULL);
	return (_set_info(arr));
}

t_philo	*init_philos(t_info *info)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * info->philos);
	if (!philos)
		return (err_return_null("Error: malloc(): Failed to allocate Memory"));
	i = 0;
	while (i < info->philos)
	{
		philos[i].id = i;
		philos[i].cnt = 0;
		philos[i].started_at = 0;
		philos[i].ate_at = 0;
		philos[i].r_fork = i;
		philos[i].l_fork = (i + 1) % info->philos;
		philos[i].info = info;
		i++;
	}
	return (philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:55 by bolee             #+#    #+#             */
/*   Updated: 2022/12/05 13:28:46 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	err_return_one(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

void	*err_return_null(char *str)
{
	err_return_one(str);
	return (NULL);
}

int	is_valid_arr(long long *arr, int n)
{
	int	i;

	if (arr[0] <= 0)
	{
		err_return_one("Error: There must be at least one philosopher");
		return (0);
	}
	i = 0;
	while (i < n)
	{
		if (arr[i] == LLONG_MAX || arr[i] == LLONG_MIN)
		{
			err_return_one("Error: Invalid Input: Please check input.");
			return (0);
		}
		else if (arr[i] < 0)
		{
			err_return_one("Error: Invalid Input: Please input positive value");
			return (0);
		}
		i++;
	}
	return (1);
}

void	logger(t_philo *philo, int id, const char *str)
{
	pthread_mutex_lock(&(philo->info->print));
	if (philo->info->flag == 0)
		printf("%ld %d %s\n", (get_time() - philo->started_at) / 1000, id, str);
	pthread_mutex_unlock(&(philo->info->print));
}

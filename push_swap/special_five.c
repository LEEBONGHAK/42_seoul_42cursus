/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:54:42 by bolee             #+#    #+#             */
/*   Updated: 2022/06/20 21:54:43 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_min(t_list *a)
{
	long	min;
	long	tmp;

	min = 2147483647;
	while (a)
	{
		tmp = *((long *)a->content);
		if (min > tmp)
			min = tmp;
		a = a->next;
	}
	return (min);
}

static long	find_min_two(t_list *a)
{
	long	min;
	long	min_two;
	long	tmp;

	min = find_min(a);
	min_two = 2147483647;
	while (a)
	{
		tmp = *((long *)a->content);
		if (tmp > min && min_two > tmp)
			min_two = tmp;
		a = a->next;
	}
	return (min_two);
}

static void	sort_five(t_list **a, t_list **b, long min, long min_two)
{
	int		cnt;
	long	tmp;

	cnt = 0;
	while (1)
	{
		if (cnt == 2)
			break ;
		tmp = *((long *)(*a)->content);
		if (tmp == min || tmp == min_two)
		{
			pa_pb(a, b, 1, NULL);
			cnt++;
			continue ;
		}
		ra_rb(a, b, 0, NULL);
	}
	sort_three_a_2(a);
	pa_pb(a, b, 0, NULL);
	pa_pb(a, b, 0, NULL);
	if (*((long *)(*a)->content) > *((long *)((*a)->next)->content))
		sa_sb(a, b, 0);
}

int	is_special_five(t_list **a, t_list **b)
{
	long	min;
	long	min_two;

	min = find_min(*a);
	min_two = find_min_two(*a);
	if (ft_lstsize(*a) != 5)
		return (0);
	if (is_a_sorted(*a, 5))
		return (1);
	sort_five(a, b, min, min_two);
	return (1);
}

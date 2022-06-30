/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_b_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:15:01 by bolee             #+#    #+#             */
/*   Updated: 2022/06/16 16:15:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(long *three, t_list **b)
{
	if (three[0] < three[1] && three[1] < three[2])
	{
		rotate_stack(b);
		swap_stack(b);
		save_and_print_result("rb\nsb\n", 1);
	}
	else if (three[0] < three[1] && three[1] > three[2] && three[0] < three[2])
	{
		rotate_stack(b);
		save_and_print_result("rb\n", 1);
	}
	else if (three[0] > three[1] && three[1] < three[2] && three[0] < three[2])
	{
		reverse_rotate_stack(b);
		save_and_print_result("rrb\n", 1);
	}
}

static void	case_two(long *three, t_list **b)
{
	if (three[0] < three[1] && three[1] > three[2] && three[0] > three[2])
	{
		swap_stack(b);
		save_and_print_result("sb\n", 1);
	}
	else if (three[0] > three[1] && three[0] > three[2] && three[1] < three[2])
	{
		swap_stack(b);
		rotate_stack(b);
		save_and_print_result("sb\nrb\n", 1);
	}
	else if (three[0] > three[1] && three[1] > three[2])
		return ;
}

void	sort_three_b_2(t_list **b, t_list **a)
{
	int		i;
	t_list	*tmp;
	long	three[3];

	i = 0;
	tmp = *b;
	while (i < 3)
	{
		three[i] = *((long *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	case_one(three, b);
	case_two(three, b);
	i = 0;
	while (i < 3)
	{
		pa_pb(a, b, 0, NULL);
		i++;
	}
}

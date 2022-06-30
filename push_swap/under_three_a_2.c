/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_a_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:14:53 by bolee             #+#    #+#             */
/*   Updated: 2022/06/16 16:14:55 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(long *three, t_list **a)
{
	if (three[0] < three[1] && three[1] < three[2])
		return ;
	else if (three[0] < three[1] && three[1] > three[2] && three[0] < three[2])
	{
		reverse_rotate_stack(a);
		swap_stack(a);
		save_and_print_result("rra\nsa\n", 1);
	}
	else if (three[0] > three[1] && three[1] < three[2] && three[0] < three[2])
	{
		swap_stack(a);
		save_and_print_result("sa\n", 1);
	}
	else if (three[0] < three[1] && three[1] > three[2] && three[0] > three[2])
	{
		reverse_rotate_stack(a);
		save_and_print_result("rra\n", 1);
	}
}

static void	case_two(long *three, t_list **a)
{
	if (three[0] > three[1] && three[0] > three[2] && three[1] < three[2])
	{
		rotate_stack(a);
		save_and_print_result("ra\n", 1);
	}
	else if (three[0] > three[1] && three[1] > three[2])
	{
		rotate_stack(a);
		swap_stack(a);
		save_and_print_result("ra\nsa\n", 1);
	}
}

void	sort_three_a_2(t_list **a)
{
	int		i;
	t_list	*tmp;
	long	three[3];

	i = 0;
	tmp = *a;
	while (i < 3)
	{
		three[i] = *((long *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	case_one(three, a);
	case_two(three, a);
}

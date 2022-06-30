/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:02:31 by bolee             #+#    #+#             */
/*   Updated: 2022/06/16 16:15:09 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(long *three, t_list **b, t_list **a)
{
	if (three[0] < three[1] && three[1] < three[2])
	{
		swap_stack(b);
		push_stack(b, a);
		swap_stack(b);
		push_stack(b, a);
		swap_stack(a);
		push_stack(b, a);
		save_and_print_result("sb\npa\nsb\npa\nsa\npa\n", 1);
	}
	else if (three[0] < three[1] && three[1] > three[2] && three[0] < three[2])
	{
		swap_stack(b);
		push_stack(b, a);
		swap_stack(b);
		push_stack(b, a);
		push_stack(b, a);
		save_and_print_result("sb\npa\nsb\npa\npa\n", 1);
	}
}

static void	case_two(long *three, t_list **b, t_list **a)
{
	if (three[0] < three[1] && three[1] > three[2] && three[0] > three[2])
	{
		swap_stack(b);
		push_stack(b, a);
		push_stack(b, a);
		push_stack(b, a);
		save_and_print_result("sb\npa\npa\npa\n", 1);
	}
	else if (three[0] > three[1] && three[0] > three[2] && three[1] < three[2])
	{
		push_stack(b, a);
		swap_stack(b);
		push_stack(b, a);
		push_stack(b, a);
		save_and_print_result("pa\nsb\npa\npa\n", 1);
	}
	else if (three[0] > three[1] && three[1] > three[2])
	{
		push_stack(b, a);
		push_stack(b, a);
		push_stack(b, a);
		save_and_print_result("pa\npa\npa\n", 1);
	}
}

static void	sort_three_b(t_list **b, t_list **a)
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
	case_one(three, b, a);
	if (three[0] > three[1] && three[1] < three[2] && three[0] < three[2])
	{
		push_stack(b, a);
		swap_stack(b);
		push_stack(b, a);
		swap_stack(a);
		push_stack(b, a);
		save_and_print_result("pa\nsb\npa\nsa\npa\n", 1);
	}
	case_two(three, b, a);
}

static void	sort_two_b(t_list **b, t_list **a)
{
	if (*((long *)(*b)->content) < *((long *)((*b)->next)->content))
	{
		swap_stack(b);
		save_and_print_result("sb\n", 1);
	}
	pa_pb(a, b, 0, NULL);
	pa_pb(a, b, 0, NULL);
}

void	under_three_b(t_list **a, t_list **b, int n)
{
	int	b_size;

	b_size = ft_lstsize(*b);
	if (n == 3 && b_size > 3)
		sort_three_b(b, a);
	else if (n == 3 && b_size == 3)
		sort_three_b_2(b, a);
	else if (n == 3 && b_size == 2)
		sort_two_b(b, a);
	else if (n == 3)
		pa_pb(a, b, 0, NULL);
	else if (n == 2 && b_size >= 2)
		sort_two_b(b, a);
	else if (n == 2 || n == 1)
		pa_pb(a, b, 0, NULL);
}

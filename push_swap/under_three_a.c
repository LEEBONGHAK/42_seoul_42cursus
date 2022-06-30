/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:38:13 by bolee             #+#    #+#             */
/*   Updated: 2022/06/10 15:38:17 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(long *three, t_list **a)
{
	if (three[0] < three[1] && three[1] < three[2])
		return ;
	else if (three[0] < three[1] && three[1] > three[2] && three[0] < three[2])
	{
		rotate_stack(a);
		swap_stack(a);
		reverse_rotate_stack(a);
		save_and_print_result("ra\nsa\nrra\n", 1);
	}
	else if (three[0] > three[1] && three[1] < three[2] && three[0] < three[2])
	{
		swap_stack(a);
		save_and_print_result("sa\n", 1);
	}
	else if (three[0] < three[1] && three[1] > three[2] && three[0] > three[2])
	{
		rotate_stack(a);
		swap_stack(a);
		reverse_rotate_stack(a);
		swap_stack(a);
		save_and_print_result("ra\nsa\nrra\nsa\n", 1);
	}
}

static void	case_two(long *three, t_list **a)
{
	if (three[0] > three[1] && three[0] > three[2] && three[1] < three[2])
	{
		swap_stack(a);
		rotate_stack(a);
		swap_stack(a);
		reverse_rotate_stack(a);
		save_and_print_result("sa\nra\nsa\nrra\n", 1);
	}
	else if (three[0] > three[1] && three[1] > three[2])
	{
		swap_stack(a);
		rotate_stack(a);
		swap_stack(a);
		reverse_rotate_stack(a);
		swap_stack(a);
		save_and_print_result("sa\nra\nsa\nrra\nsa\n", 1);
	}
}

static void	sort_three_a(t_list **a)
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

static void	sort_two_a(t_list **a)
{
	if (*a && (*a)->next && \
	*((long *)(*a)->content) > *((long *)((*a)->next)->content))
	{
		swap_stack(a);
		save_and_print_result("sa\n", 1);
	}
}

void	under_three_a(t_list **a, int n)
{
	int	a_size;

	a_size = ft_lstsize(*a);
	if (n == 3 && a_size > 3)
		sort_three_a(a);
	else if (n == 3 && a_size == 3)
		sort_three_a_2(a);
	else if ((n == 3 && a_size < 2) || (n <= 2 && n >= 0))
		sort_two_a(a);
}

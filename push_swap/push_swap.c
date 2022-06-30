/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:46:24 by bolee             #+#    #+#             */
/*   Updated: 2022/06/19 19:48:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_list **a, t_list **b, int n, t_cnt cnts);
static void	b_to_a(t_list **a, t_list **b, int n, t_cnt cnts);

static void	a_to_b_process(t_list **a, t_list **b, int n, t_cnt *cnts)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < n)
	{
		tmp = *((long *)(*a)->content);
		if (tmp >= cnts->pivot_big)
			ra_rb(a, b, 0, cnts);
		else
		{
			pa_pb(a, b, 1, cnts);
			if (tmp >= cnts->pivot_small)
				ra_rb(a, b, 1, cnts);
		}
		i++;
	}
}

static void	a_to_b(t_list **a, t_list **b, int n, t_cnt cnts)
{
	if (is_special_five(a, b))
		return ;
	if (n <= 3)
	{
		under_three_a(a, n);
		return ;
	}
	if (!is_a_sorted(*a, n))
	{
		get_pivot(a, n, &cnts);
		init_cnts(&cnts);
		a_to_b_process(a, b, n, &cnts);
		rra_rrb_rrr(a, b, cnts);
		a_to_b(a, b, cnts.ra_cnt, cnts);
		b_to_a(a, b, cnts.rb_cnt, cnts);
		b_to_a(a, b, cnts.pb_cnt - cnts.rb_cnt, cnts);
	}
}

static void	b_to_a_process(t_list **a, t_list **b, int n, t_cnt *cnts)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < n)
	{
		tmp = *((long *)(*b)->content);
		if (tmp < cnts->pivot_small)
			ra_rb(a, b, 1, cnts);
		else
		{
			pa_pb(a, b, 0, cnts);
			if (tmp < cnts->pivot_big)
				ra_rb(a, b, 0, cnts);
		}
		i++;
	}
}

static void	b_to_a(t_list **a, t_list **b, int n, t_cnt cnts)
{
	if (n <= 3)
	{
		under_three_b(a, b, n);
		return ;
	}
	get_pivot(b, n, &cnts);
	init_cnts(&cnts);
	b_to_a_process(a, b, n, &cnts);
	a_to_b(a, b, cnts.pa_cnt - cnts.ra_cnt, cnts);
	rra_rrb_rrr(a, b, cnts);
	a_to_b(a, b, cnts.ra_cnt, cnts);
	b_to_a(a, b, cnts.rb_cnt, cnts);
}

void	push_swap(t_list **a)
{
	t_list	*b;
	t_cnt	cnts;

	b = NULL;
	cnts.pivot_small = 0;
	cnts.pivot_big = 0;
	init_cnts(&cnts);
	a_to_b(a, &b, ft_lstsize(*a), cnts);
	save_and_print_result(NULL, 0);
}

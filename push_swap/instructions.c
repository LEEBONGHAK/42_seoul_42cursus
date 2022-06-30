/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:37:40 by bolee             #+#    #+#             */
/*   Updated: 2022/06/08 12:37:42 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **a, t_list **b, int flag)
{
	if (flag == 0)
	{
		swap_stack(a);
		save_and_print_result("sa\n", 1);
	}
	else if (flag == 1)
	{
		swap_stack(b);
		save_and_print_result("sb\n", 1);
	}
}

void	pa_pb(t_list **a, t_list **b, int flag, t_cnt *cnts)
{
	if (flag == 0)
	{
		if (*b)
		{
			push_stack(b, a);
			save_and_print_result("pa\n", 1);
		}
		if (cnts)
			cnts->pa_cnt++;
	}
	else if (flag == 1)
	{
		if (*a)
		{
			push_stack(a, b);
			save_and_print_result("pb\n", 1);
		}
		if (cnts)
			cnts->pb_cnt++;
	}
}

void	ra_rb(t_list **a, t_list **b, int flag, t_cnt *cnts)
{
	if (flag == 0)
	{
		if (cnts)
			cnts->ra_cnt++;
		if (ft_lstsize(*a) > 1)
		{
			rotate_stack(a);
			save_and_print_result("ra\n", 1);
		}
	}
	else if (flag == 1)
	{
		if (cnts)
			cnts->rb_cnt++;
		if (ft_lstsize(*b) > 1)
		{
			rotate_stack(b);
			save_and_print_result("rb\n", 1);
		}
	}
}

void	rra_rrb(t_list **a, t_list **b, int flag)
{
	if (flag == 0 && ft_lstsize(*a) > 1)
	{
		reverse_rotate_stack(a);
		save_and_print_result("rra\n", 1);
	}
	else if (flag == 1 && ft_lstsize(*b) > 1)
	{
		reverse_rotate_stack(b);
		save_and_print_result("rrb\n", 1);
	}
}

void	rra_rrb_rrr(t_list **a, t_list **b, t_cnt cnts)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cnts.ra_cnt || j < cnts.rb_cnt)
	{
		if (i < cnts.ra_cnt && j < cnts.rb_cnt)
		{
			rra_rrb(a, b, 0);
			rra_rrb(a, b, 1);
		}
		else if (i < cnts.ra_cnt)
			rra_rrb(a, b, 0);
		else if (j < cnts.rb_cnt)
			rra_rrb(a, b, 1);
		i++;
		j++;
	}
}

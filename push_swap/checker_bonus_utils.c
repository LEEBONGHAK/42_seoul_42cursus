/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:40:09 by bolee             #+#    #+#             */
/*   Updated: 2022/06/19 20:42:39 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (*((long *)a->content) > *((long *)(a->next)->content))
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_empty(t_list *b)
{
	if (b == NULL)
		return (1);
	return (0);
}

static void	deal_double_instructions(t_list **a, t_list **b, int flag)
{
	if (flag == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (flag == 1)
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else if (flag == 2)
	{
		swap_stack(a);
		swap_stack(b);
	}
}

static void	execute_instructions(t_list **a, t_list **b, char *ptr)
{
	if (ft_strncmp(ptr, "pa\n", 3) == 0)
		push_stack(b, a);
	else if (ft_strncmp(ptr, "pb\n", 3) == 0)
		push_stack(a, b);
	else if (ft_strncmp(ptr, "ra\n", 3) == 0)
		rotate_stack(a);
	else if (ft_strncmp(ptr, "rb\n", 3) == 0)
		rotate_stack(b);
	else if (ft_strncmp(ptr, "rr\n", 3) == 0)
		deal_double_instructions(a, b, 0);
	else if (ft_strncmp(ptr, "rra\n", 4) == 0)
		reverse_rotate_stack(a);
	else if (ft_strncmp(ptr, "rrb\n", 4) == 0)
		reverse_rotate_stack(b);
	else if (ft_strncmp(ptr, "rrr\n", 4) == 0)
		deal_double_instructions(a, b, 1);
	else if (ft_strncmp(ptr, "sa\n", 3) == 0)
		swap_stack(a);
	else if (ft_strncmp(ptr, "sb\n", 3) == 0)
		swap_stack(b);
	else if (ft_strncmp(ptr, "ss\n", 3) == 0)
		deal_double_instructions(a, b, 2);
	else
		err_control();
}

void	input_and_execute(t_list **a, t_list **b)
{
	char	*ptr;
	ssize_t	rfd;

	ptr = (char *)malloc(sizeof(char) * 42);
	if (!ptr)
		err_control();
	rfd = 1;
	while (rfd)
	{
		rfd = read(0, ptr, 41);
		if (rfd < 0)
			err_control();
		ptr[rfd] = '\0';
		if (rfd == 0)
			break ;
		execute_instructions(a, b, ptr);
	}
	free(ptr);
}

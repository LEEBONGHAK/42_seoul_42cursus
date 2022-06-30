/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:39:26 by bolee             #+#    #+#             */
/*   Updated: 2022/06/06 21:12:56 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **lst)
{
	void	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->content;
		(*lst)->content = ((*lst)->next)->content;
		((*lst)->next)->content = tmp;
	}
}

void	push_stack(t_list **pull, t_list **put)
{
	t_list	*new_head;
	t_list	*new_node;
	void	*tmp;

	if (*pull)
	{
		tmp = (*pull)->content;
		new_head = (*pull)->next;
		free(*pull);
		*pull = new_head;
		new_node = ft_lstnew(tmp);
		if (!new_node)
			err_control();
		ft_lstadd_front(put, new_node);
	}
}

void	rotate_stack(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		tmp->next = 0;
		ft_lstadd_back(lst, tmp);
	}
}

void	reverse_rotate_stack(t_list **lst)
{
	t_list	*first_node;
	t_list	*last_node;

	if (*lst && ft_lstsize(*lst) > 1)
	{
		first_node = *lst;
		last_node = ft_lstlast(*lst);
		while (*lst)
		{
			if ((*lst)->next == last_node)
				(*lst)->next = 0;
			*lst = (*lst)->next;
		}
		*lst = first_node;
		ft_lstadd_front(lst, last_node);
	}
}

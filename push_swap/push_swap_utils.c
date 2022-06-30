/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:41 by bolee             #+#    #+#             */
/*   Updated: 2022/06/07 13:30:43 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(long *tab, int n)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	get_pivot(t_list **lst, int n, t_cnt *cnts)
{
	int		i;
	t_list	*tmp;
	long	*elements;

	i = 0;
	tmp = *lst;
	elements = (long *)malloc(sizeof(long) * n);
	if (!elements)
		err_control();
	while (i < n)
	{
		elements[i] = *((long *) tmp->content);
		tmp = tmp->next;
		i++;
	}
	bubble_sort(elements, n);
	cnts->pivot_small = elements[n / 3];
	cnts->pivot_big = elements[2 * n / 3];
	free(elements);
}

void	init_cnts(t_cnt *cnts)
{
	cnts->pa_cnt = 0;
	cnts->pb_cnt = 0;
	cnts->ra_cnt = 0;
	cnts->rb_cnt = 0;
}

int	is_a_sorted(t_list *a, int n)
{
	int	i;

	i = 0;
	while (i < n && a->next)
	{
		if (*((long *)a->content) > *((long *)(a->next)->content))
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

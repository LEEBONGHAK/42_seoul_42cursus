/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:18:15 by bolee             #+#    #+#             */
/*   Updated: 2022/06/25 18:19:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicated(t_list *lst, long num)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		if (num == *((long *)tmp->content))
			err_control();
		lst = lst->next;
	}
}

static int	double_arr_size(char **arr)
{
	int	cnt;

	cnt = 0;
	while (arr[cnt])
		cnt++;
	return (cnt);
}

static void	iner_init_stack(char **split_arr, t_list **a)
{
	int		i;
	long	*tmp;
	t_list	*new;

	i = double_arr_size(split_arr) - 1;
	while (0 <= i)
	{
		tmp = (long *)malloc(sizeof(long));
		if (!tmp)
			err_control();
		*tmp = ft_atol(split_arr[i]);
		check_duplicated(*a, *tmp);
		new = ft_lstnew(tmp);
		if (!new)
			err_control();
		ft_lstadd_front(a, new);
		free(split_arr[i]);
		i--;
	}
	free(split_arr);
}

static int	init_stack(int argc, char **argv, t_list **a)
{
	int		i;
	t_list	*tmp;
	char	**split;

	i = argc - 1;
	while (0 < i)
	{
		if (!argv[i][0])
			err_control();
		split = ft_split(argv[i], ' ');
		iner_init_stack(split, a);
		i--;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (*((long *)tmp->content) > *((long *)(tmp->next)->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc == 1)
		return (0);
	a = NULL;
	if (init_stack(argc, argv, &a) || ft_lstsize(a) == 1)
	{
		ft_lstclear(&a, free);
		return (0);
	}
	if (*((long *)a->content) > *((long *)(a->next)->content))
		sa_sb(&a, NULL, 0);
	push_swap(&a);
	ft_lstclear(&a, free);
	return (0);
}

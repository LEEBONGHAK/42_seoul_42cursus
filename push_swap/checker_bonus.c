/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:40:01 by bolee             #+#    #+#             */
/*   Updated: 2022/06/19 18:40:02 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

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
		if (*tmp > 2147483647 || *tmp < -2147483648)
			err_control();
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

static void	init_stack(int argc, char **argv, t_list **a)
{
	int		i;
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
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	init_stack(argc, argv, &a);
	input_and_execute(&a, &b);
	if (is_sorted(a) && is_empty(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}

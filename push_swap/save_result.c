/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:14:24 by bolee             #+#    #+#             */
/*   Updated: 2022/06/19 18:37:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	print_case(char *a, char *b, int *i)
{
	if ((!ft_strncmp(a, "sa", 2) && !ft_strncmp(b, "sb", 2)) \
	|| (!ft_strncmp(a, "sb", 2) && !ft_strncmp(b, "sa", 2)))
		ft_printf("ss\n");
	else if ((!ft_strncmp(a, "ra", 2) && !ft_strncmp(b, "rb", 2)) \
	|| (!ft_strncmp(a, "rb", 2) && !ft_strncmp(b, "ra", 2)))
		ft_printf("rr\n");
	else if ((!ft_strncmp(a, "rra", 3) && !ft_strncmp(b, "rrb", 3)) \
	|| (!ft_strncmp(a, "rrb", 3) && !ft_strncmp(b, "rra", 3)))
		ft_printf("rrr\n");
	else
	{
		ft_printf("%s\n", a);
		(*i)++;
		return ;
	}
	*i += 2;
}

static void	print_result(char *str)
{
	int		i;
	char	**res;

	res = ft_split(str, '\n');
	if (!res)
		err_control();
	i = 0;
	while (res[i])
	{
		if (res[i + 1])
			print_case(res[i], res[i + 1], &i);
		else
		{
			ft_printf("%s\n", res[i]);
			i++;
		}
	}
	free_double_arr(res);
}

void	save_and_print_result(char *str, int flag)
{
	static char	*s;
	char		*tmp;

	if (flag)
	{
		if (!s)
		{
			s = ft_strdup(str);
			if (!s)
				err_control();
			return ;
		}
		tmp = ft_strjoin(s, str);
		if (!tmp)
			err_control();
		free(s);
		s = tmp;
		return ;
	}
	if (s)
	{
		print_result(s);
		free(s);
	}
}

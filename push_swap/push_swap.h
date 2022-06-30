/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:48:27 by bolee             #+#    #+#             */
/*   Updated: 2022/06/25 15:04:30 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* my header files */
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

/* s_cnt structure */
typedef struct s_cnt
{
	int		ra_cnt;
	int		pb_cnt;
	int		rb_cnt;
	int		pa_cnt;
	long	pivot_small;
	long	pivot_big;
}	t_cnt;

/* in instructions_utils.c */
void	swap_stack(t_list **lst);
void	push_stack(t_list **pull, t_list **put);
void	rotate_stack(t_list **lst);
void	reverse_rotate_stack(t_list **lst);

/* in instructions.c */
void	sa_sb(t_list **a, t_list **b, int flag);
void	pa_pb(t_list **a, t_list **b, int flag, t_cnt *cnts);
void	ra_rb(t_list **a, t_list **b, int flag, t_cnt *cnts);
void	rra_rrb(t_list **a, t_list **b, int flag);
void	rra_rrb_rrr(t_list **a, t_list **b, t_cnt cnts);

/* in main_utils.c */
void	err_control(void);
long	ft_atol(const char *str);

/* in push_swap_utils.c */
void	get_pivot(t_list **lst, int n, t_cnt *cnts);
void	init_cnts(t_cnt *cnts);
int		is_a_sorted(t_list *a, int n);

/* in push_swap.c */
void	push_swap(t_list **a);

/* in under_three_*.c */
void	under_three_a(t_list **a, int n);
void	under_three_b(t_list **a, t_list **b, int n);
void	sort_three_a_2(t_list **a);
void	sort_three_b_2(t_list **b, t_list **a);

/* in save_result.c */
void	save_and_print_result(char *str, int flag);

/* in special_five.c */
int		is_special_five(t_list **a, t_list **b);

#endif

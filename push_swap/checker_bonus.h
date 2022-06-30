/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:46:07 by bolee             #+#    #+#             */
/*   Updated: 2022/06/18 15:46:08 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/* in checker_bonus_utils.c */
int		is_sorted(t_list *a);
int		is_empty(t_list *b);
void	input_and_execute(t_list **a, t_list **b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:35 by bolee             #+#    #+#             */
/*   Updated: 2022/03/30 11:21:37 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_node(t_list *lst)
{
	if (lst->flag)
	{
		if (write(1, &(lst->content)[0], 1) == -1)
			return (-1);
		return (1);
	}
	return (print_str(lst->content));
}

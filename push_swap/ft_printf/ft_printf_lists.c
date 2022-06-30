/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:38 by bolee             #+#    #+#             */
/*   Updated: 2022/03/24 19:56:38 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_plist	*lstnew(char c, char *content)
{
	t_plist	*new_lst;

	if (!content)
		return (NULL);
	new_lst = (t_plist *)malloc(sizeof(t_plist));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = 0;
	new_lst->flag = 0;
	if (c == 'c' || c == '%')
		new_lst->flag = 1;
	return (new_lst);
}

static t_plist	*ft_lstlast(t_plist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	pf_lstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*tmp;

	if (!new)
		return (0);
	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
	return (1);
}

t_plist	*pf_lstclear(t_plist **lst)
{
	t_plist	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

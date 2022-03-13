#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;
	t_list	*tmp;

	new_lst = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			while (new_lst)
			{
				tmp = new_lst;
				new_lst = new_lst->next;
				del(tmp->content);
				free(tmp);
			}
			return (0);
		}
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}

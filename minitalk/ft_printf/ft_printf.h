/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:16:04 by bolee             #+#    #+#             */
/*   Updated: 2022/06/06 21:15:16 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

typedef struct s_plist
{
	char			*content;
	int				flag;
	struct s_plist	*next;
}	t_plist;

/* in ft_printf.c */
int		ft_printf(const char *format, ...);

/* in ft_printf_utils.c */
int		pf_strlen(const char *str);
int		haveconversions(const char *str);
int		isconversions(const char c);
int		print_str(const char *res);
void	pf_strlcpy(char *dst, const char *src, int size);

/* in ft_printf_lists.c */
t_plist	*lstnew(char c, char *content);
int		pf_lstadd_back(t_plist **lst, t_plist *new);
t_plist	*pf_lstclear(t_plist **lst);

/* in ft_printf_arg_cs.c */
char	*arg_c(int c);
char	*arg_s(char *s);

/* in ft_printf_arg_p.c */
char	*arg_p(void *p);

/* in ft_printf_arg_xX.c */
char	*arg_x_largex(long x, int flag);

/* in printf_itoa_arg_u.c */
char	*pf_itoa(int n);
char	*arg_u(unsigned int u);

/* in print_node.c */
int		print_node(t_plist *lst);

#endif

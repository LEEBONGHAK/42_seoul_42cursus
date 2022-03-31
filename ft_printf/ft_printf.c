/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:33:59 by bolee             #+#    #+#             */
/*   Updated: 2022/03/28 18:11:29 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

static int	print_lst(t_list *lst)
{
	int		cnt_tmp;
	long	cnt;
	t_list	*tmp;

	cnt = 0;
	if (!lst)
		return (-1);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		cnt_tmp = print_node(tmp);
		free(tmp->content);
		free(tmp);
		if (cnt_tmp == -1)
			return ((int) pf_lstclear(&lst) - 1);
		cnt += cnt_tmp;
		if (cnt > INT_MAX)
			return ((int) pf_lstclear(&lst) - 1);
	}
	free(lst);
	return (cnt);
}

static char	*get_arg(char c, va_list args)
{
	char	*arg;

	if (c == 'c')
		arg = arg_c(va_arg(args, int));
	else if (c == 's')
		arg = arg_s(va_arg(args, char *));
	else if (c == 'p')
		arg = arg_p(va_arg(args, void *));
	else if (c == 'd')
		arg = pf_itoa(va_arg(args, int));
	else if (c == 'i')
		arg = pf_itoa(va_arg(args, int));
	else if (c == 'u')
		arg = arg_u(va_arg(args, unsigned int));
	else if (c == 'x')
		arg = arg_xX(va_arg(args, long), 0);
	else if (c == 'X')
		arg = arg_xX(va_arg(args, long), 1);
	else
		arg = arg_c('%');
	return (arg);
}

static char	*make_content(const char *format, int i, int j)
{
	char	*content;

	content = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!content)
		return (NULL);
	pf_strlcpy(content, format + j, i - j + 1);
	return (content);
}

static t_list	*make_lst(const char *format, va_list args)
{
	int		i;
	int		j;
	t_list	*res;

	i = 0;
	j = 0;
	res = NULL;
	while (format[i])
	{
		if (format[i] == '%' && isconversions(format[i + 1]))
		{
			if (!pf_lstadd_back(&res, lstnew(0, make_content(format, i, j))) \
				|| !pf_lstadd_back(&res, lstnew(format[i + 1], \
				get_arg(format[i + 1], args))))
				return (pf_lstclear(&res));
			i += 2;
			j = i;
			continue ;
		}
		i++;
	}
	if (!pf_lstadd_back(&res, lstnew(0, make_content(format, i, j))))
		return (pf_lstclear(&res));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*res;

	if (!haveconversions(format))
		return (print_str(format));
	va_start(args, format);
	res = make_lst(format, args);
	va_end(args);
	return (print_lst(res));
}

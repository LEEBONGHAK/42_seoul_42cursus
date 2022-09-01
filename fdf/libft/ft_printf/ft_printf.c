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
		arg = arg_x(va_arg(args, long), 0);
	else if (c == 'X')
		arg = arg_x(va_arg(args, long), 1);
	else
		arg = arg_c('%');
	return (arg);
}

static int	print_args(char c, va_list args)
{
	char	*str;
	int		tmp;

	str = get_arg(c, args);
	if (!str)
		return (-1);
	tmp = print_str(str);
	if (tmp == -1)
		return (-1);
	return (tmp);
}

static int	print_format(const char *format, va_list args)
{
	int		i;
	int		cnt;
	int		tmp;

	cnt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && isconversions(format[i + 1]))
		{
			tmp = print_args(format[i + 1], args);
			if (tmp == -1)
				return (-1);
			cnt += tmp;
			i += 2;
			continue ;
		}
		if (write(1, format + i, 1) == -1)
			return (-1);
		cnt++;
		i++;
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	if (!haveconversions(format))
		return (print_str(format));
	va_start(args, format);
	res = print_format(format, args);
	va_end(args);
	return (res);
}

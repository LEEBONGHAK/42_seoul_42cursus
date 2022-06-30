/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:54:52 by bolee             #+#    #+#             */
/*   Updated: 2022/03/24 20:06:04 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*arg_c(int c)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = c;
	return (tmp);
}

char	*arg_s(char *s)
{
	char	*tmp;
	int		size;

	if (!s)
	{
		tmp = (char *)malloc(sizeof(char) * 7);
		if (!tmp)
			return (NULL);
		pf_strlcpy(tmp, "(null)", 7);
		return (tmp);
	}
	size = pf_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	pf_strlcpy(tmp, s, size + 1);
	return (tmp);
}

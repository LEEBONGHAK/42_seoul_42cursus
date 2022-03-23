/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:02:17 by bolee             #+#    #+#             */
/*   Updated: 2022/03/22 16:02:18 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	gnl_havenewline(const char *s)
{
	int	i;
	int	size;

	i = 0;
	size = gnl_strlen(s);
	while (i < size)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_size;
	size_t	s2_size;
	char	*new_str;

	s2_size = gnl_strlen(s2);
	if (!s1)
	{
		new_str = (char *)malloc(s2_size + 1);
		gnl_strlcpy(new_str, s2, s2_size + 1);
		return (new_str);
	}
	s1_size = gnl_strlen(s1);
	total_len = s1_size + s2_size + 1;
	new_str = (char *)malloc(total_len * sizeof(char));
	if (!new_str)
		return (0);
	gnl_strlcpy(new_str, s1, s1_size + 1);
	gnl_strlcpy(new_str + s1_size, s2, s2_size + 1);
	return (new_str);
}

void	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
}

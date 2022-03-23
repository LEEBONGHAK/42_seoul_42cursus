/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:48:49 by bolee             #+#    #+#             */
/*   Updated: 2022/03/23 14:16:59 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_tmp(char *tmp, char *str, char *ptr)
{
	char	*new_tmp;

	if (!tmp)
	{
		tmp = gnl_strjoin(str, ptr);
		return (tmp);
	}
	new_tmp = gnl_strjoin(tmp, ptr);
	free(tmp);
	tmp = NULL;
	return (new_tmp);
}

static char	*set_str(char *tmp, char *str)
{
	size_t	i;
	char	*str_tmp;

	i = 0;
	if (!gnl_havenewline(tmp))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (tmp[i] != '\n')
		i++;
	str_tmp = (char *)malloc(sizeof(char) * (gnl_strlen(tmp) - i));
	if (!str_tmp)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	gnl_strlcpy(str_tmp, tmp + i + 1, gnl_strlen(tmp) - i);
	free(str);
	str = str_tmp;
	return (str);
}

static char	*set_res(char *tmp)
{
	size_t	i;
	char	*new_tmp;

	i = 0;
	if (!gnl_havenewline(tmp))
		return (tmp);
	while (tmp[i] != '\n')
		i++;
	new_tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_tmp)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	gnl_strlcpy(new_tmp, tmp, i + 2);
	free(tmp);
	tmp = NULL;
	return (new_tmp);
}

static char	*while_read(int fd, size_t nbyte, char *tmp, char *str)
{
	char	*ptr;
	ssize_t	rfd;

	ptr = (char *)malloc(sizeof(char) * (nbyte + 1));
	if (!ptr)
		return (NULL);
	rfd = 1;
	while (rfd)
	{
		rfd = read(fd, ptr, nbyte);
		if (rfd == -1)
		{
			free(ptr);
			ptr = NULL;
			return (NULL);
		}
		ptr[rfd] = '\0';
		tmp = set_tmp(tmp, str, ptr);
		if (gnl_havenewline(tmp) || rfd < nbyte || rfd == 0)
			break ;
	}
	free(ptr);
	ptr = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	size_t		nbyte;

	tmp = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	nbyte = BUFFER_SIZE;
	if (BUFFER_SIZE > SIZE_MAX)
		nbyte = SIZE_MAX;
	tmp = while_read(fd, nbyte, tmp, str);
	if (!tmp)
		return (NULL);
	if (!tmp[0])
	{
		free(tmp);
		free(str);
		tmp = NULL;
		str = NULL;
		return (NULL);
	}
	str = set_str(tmp, str);
	tmp = set_res(tmp);
	return (tmp);
}

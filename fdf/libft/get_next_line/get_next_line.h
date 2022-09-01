/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:09:44 by bolee             #+#    #+#             */
/*   Updated: 2022/07/05 15:09:49 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* int get_next_line.c */
char	*get_next_line(int fd);

/* in get_next_line_utils.c */
size_t	gnl_strlen(const char *s);
int		gnl_havenewline(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
void	gnl_strlcpy(char *dst, const char *src, size_t size);

#endif

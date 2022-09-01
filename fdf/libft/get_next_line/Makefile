# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 12:22:33 by bolee             #+#    #+#              #
#    Updated: 2022/03/23 12:36:11 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			=	ar
ARFLAG		=	-rcusv
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
SRCS		=	get_next_line.c \
				get_next_line_utils.c
OBJS		=	$(SRCS:.c=.o)
INCULDE		=	-I.
NAME		=	libgnl.a

$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $?

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $?

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

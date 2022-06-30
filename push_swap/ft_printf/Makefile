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
SRCS		=	ft_printf.c \
				ft_printf_utils.c \
				ft_printf_lists.c \
				ft_printf_itoa_arg_u.c \
				ft_printf_arg_xX.c \
				ft_printf_arg_p.c \
				ft_printf_arg_cs.c \
				print_node.c
OBJS		=	$(SRCS:.c=.o)
INCULDE		=	-I.
NAME		=	libftprintf.a

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
fclean:
	make clean
	rm -f $(NAME)

.PHONY: re
re:
	make fclean
	make all

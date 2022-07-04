# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 20:54:49 by bolee             #+#    #+#              #
#    Updated: 2022/06/22 20:54:51 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
NAME			=	minitalk

# Mandatory
C_SERVER		=	server.c \
					minitalk_utils.c
C_SERVER_OBJS	=	$(C_SERVER:.c=.o)
SERVER			=	server

C_CLIENT		=	client.c \
					client_utils.c \
					minitalk_utils.c
C_CLIENT_OBJS	=	$(C_CLIENT:.c=.o)
CLIENT			=	client

# Bonus
C_SERVER_B		=	server_bonus.c \
					minitalk_utils.c
C_SERVER_B_OBJS	=	$(C_SERVER_B:.c=.o)
SERVER_B		=	server_bonus

C_CLIENT_B		=	client_bonus.c \
					client_utils.c \
					minitalk_utils.c
C_CLIENT_B_OBJS	=	$(C_CLIENT_B:.c=.o)
CLIENT_B		=	client_bonus

FTPRINTF_DIR	=	./ft_printf
FTPRINTF		=	$(FTPRINTF_DIR)/libftprintf.a

NAME			=	minitalk


$(NAME):
	make $(SERVER)
	make $(CLIENT)

.PHONY: all
all:
	make $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $? -o $@	

$(SERVER): $(C_SERVER_OBJS)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(FTPRINTF) $^ -o $@

$(CLIENT): $(C_CLIENT_OBJS)
	$(CC) $(CFLAG) $(FTPRINTF) $^ -o $@

.PHONY: clean
clean:
	@make -C $(FTPRINTF_DIR) clean
	rm -f $(C_SERVER_OBJS)
	rm -f $(C_CLIENT_OBJS)
	rm -f $(C_CLIENT_B_OBJS)
	rm -f $(C_SERVER_B_OBJS)

.PHONY: fclean
fclean:
	@make -C $(FTPRINTF_DIR) fclean
	make clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_B)
	rm -f $(CLIENT_B)

.PHONY: re
re:
	make fclean
	make all

.PHONY: bonus
bonus:
	make $(SERVER_B)
	make $(CLIENT_B)

$(SERVER_B): $(C_SERVER_B_OBJS)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(FTPRINTF) $^ -o $@

$(CLIENT_B): $(C_CLIENT_B_OBJS)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(FTPRINTF) $^ -o $@
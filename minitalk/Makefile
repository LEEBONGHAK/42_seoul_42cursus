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

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror

C_CLIENT	= 
SERVER		= server

C_CLIENT	=
CLIENT		= client

FTPRINTF_DIR	=	./ft_printf
FTPRINTF		=	$(FTPRINTF_DIR)/libftprintf.a

ifeq ($(MAKECMDGOALS), client)
$(CLIENT): $(C_CLIENT)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(FTPRINTF) $(C_CLIENT) -o $@
else
$(SERVER): $(C_SERVER)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(FTPRINTF) $(C_SERVER) -o $@
endif

.PHONY: all, server, client
all:
	make $(SERVER)
	make $(CLIENT)

.PHONY: clean
clean:
	@make -C $(FTPRINTF_DIR) clean

.PHONY: fclean
fclean:
	@make -C $(FTPRINTF_DIR) fclean
	rm -f $(SERVER)
	rm -f $(CLIENT)

.PHONY: re
re:
	make fclean
	make all
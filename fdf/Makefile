# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 15:32:59 by bolee             #+#    #+#              #
#    Updated: 2022/07/04 15:33:01 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
SRCS			=	fdf.c \
					fdf_utils.c \
					struct_init.c \
					get_cdn_2.c \
					get_cdn_3.c \
					draw_win.c \
					draw_win_utils.c \
					size_control.c
OBJS			=	$(SRCS:.c=.o)
NAME			= 	fdf

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

MLX_DIR			=	./mlx_mms
MLX				=	$(MLX_DIR)/libmlx.dylib
FRAMEWORK		=	-framework Cocoa \
					-framework Metal \
					-framework MetalKit \
					-framework QuartzCore

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) bonus
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLX) $(FRAMEWORK) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -f $(OBJS)

.PHONY: fclean
fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	make clean
	rm -f $(NAME)

.PHONY: re
re:
	make fclean
	make all

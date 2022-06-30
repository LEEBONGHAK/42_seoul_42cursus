CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
CFILES			=	instructions_utils.c \
					instructions.c \
					push_swap_utils.c \
					push_swap.c \
					under_three_a.c \
					under_three_b.c \
					under_three_a_2.c \
					under_three_b_2.c \
					save_result.c \
					special_five.c \
					main_utils.c \
					main.c
OBJS			=	$(CFILES:.c=.o)
NAME			= 	push_swap

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

FTPRINTF_DIR	=	./ft_printf
FTPRINTF		=	$(FTPRINTF_DIR)/libftprintf.a

BONUS			=	instructions_utils.c \
					main_utils.c \
					checker_bonus_utils.c \
					checker_bonus.c
OBJS_B			=	$(BONUS:.c=.o)
NAME_B			=	checker

ifeq ($(MAKECMDGOALS), bonus)
$(NAME_B): $(OBJS_B)
	@make -C $(LIBFT_DIR) bonus
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(LIBFT) $(FTPRINTF) $(OBJS_B) -o $@
else
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) bonus
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAG) $(LIBFT) $(FTPRINTF) $(OBJS) -o $@
endif

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(FTPRINTF_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_B)

.PHONY: fclean
fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean
	make clean
	rm -f $(NAME)
	rm -f $(NAME_B)

.PHONY: re
re:
	make fclean
	make all

.PHONY: bonus
bonus: $(NAME_B)

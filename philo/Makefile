# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolee <bolee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 13:09:05 by bolee             #+#    #+#              #
#    Updated: 2022/12/07 18:17:33 by bolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Flag and Command
CC			=	cc -g3 -fsanitize=thread
CFLAGS		=	-Wall -Wextra -Werror -pthread

# Project File
NAME		=	philo

# Project Directories
SRCSDIR		=	./

# Iclude File
INCLUDE		=	$(SRCSDIR)philo.h

# Project Files
FILES		=	main \
				initialize \
				actions \
				monitor \
				routine \
				threads \
				utils/ft_atoi \
				utils/ft_strlen \
				utils/time \
				utils/utils \

SRCS		=	$(addprefix $(SRCSDIR), $(addsuffix .c, $(FILES)))
OBJS		=	$(SRCS:.c=.o)



# Main rule
all:
	make $(NAME)


# Object rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Project file rule
$(NAME): $(OBJS)
	@echo "\033[92mBuild philosopher...\033[0m"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Make clean
clean:
	@echo "\033[92mClean object files...\033[0m"
	rm -f $(OBJS)

# Make fclean
fclean:
	@echo "\033[92mForce clean files builded...\033[0m"
	rm -f $(OBJS)
	rm -f $(NAME)


# Make re
re: 
	@echo "\033[92mRebuild philosopher project...\033[0m"
	make fclean
	make all

.PHONY: all fclean clean re

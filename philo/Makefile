# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 16:01:20 by acroisie          #+#    #+#              #
#    Updated: 2022/05/10 16:06:50 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

NAME := philo

SRCS := init.c \
		main.c \
		philo_utils.c \
		philo.c \
		print.c \
		time.c

OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :	$(addprefix objs/, $(OBJS))
			$(CC) $(CC_FLAGS) -o $(NAME) $(addprefix objs/, $(OBJS))

objs/%.o:	srcs/%.c include/philo.h Makefile
			@mkdir -p objs
			$(CC) -c $(CC_FLAGS) $< -o $@

clean :
		rm -rf objs

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all
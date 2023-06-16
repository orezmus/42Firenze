# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <sum@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:53:23 by sum               #+#    #+#              #
#    Updated: 2023/05/30 21:45:56 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
LINK = -lpthread

SRCS_DIR = ./srcs/
SRCS_LIST = main.c \
	check.c \
	init.c \
	routine.c \
	thread.c \
	utils.c
	
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

all: $(NAME)
		
$(NAME):
	$(CC) $(FLAGS) $(SRCS) $(LINK) -o $(NAME)

re: fclean all
	
clean:

fclean:   	
	rm -rf $(NAME) $(BONUS)
		
.PHONY: all re clean fclean

.SILENT:

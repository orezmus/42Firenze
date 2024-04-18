# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 17:25:16 by sum               #+#    #+#              #
#    Updated: 2023/04/13 17:25:23 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
PF = libft/ft_printf/libftprintf.a

SRCS_DIR = ./srcs/
SRCS_LIST = main.c \
	check.c \
	init.c \
	quick_sort.c \
	sort_cmd1.c \
	sort_cmd2.c \
	sort_cmd3.c \
	sorted_check.c \
	sorted_small.c \
	sort_utils.c \
	stack.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

SRCS_DIR_B = ./srcs_bonus/
SRCS_LIST_B = main.c \
	check.c \
	init.c \
	sort_cmd1.c \
	sort_cmd2.c \
	sort_cmd3.c \
	sort_utils.c \
	stack.c

SRCS_B = $(addprefix $(SRCS_DIR_B), $(SRCS_LIST_B))

all: $(NAME)
		
$(NAME):
	make -C libft
	make -C libft/ft_printf
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(PF) -o $(NAME)

bonus: 
	make -C libft
	make -C libft/ft_printf
	$(CC) $(FLAGS) $(SRCS_B) $(LIBFT) $(PF) -o $(BONUS)
	
re: fclean all
	
clean:
	make clean -C libft
	make clean -C libft/ft_printf


fclean:   	
	make fclean -C libft
	make fclean -C libft/ft_printf
	rm -rf $(NAME) $(BONUS)
		


.PHONY: all re clean fclean

.SILENT:

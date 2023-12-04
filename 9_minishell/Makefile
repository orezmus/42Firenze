# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <sum@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:04:32 by sum               #+#    #+#              #
#    Updated: 2023/11/27 22:04:35 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
LINK = -lreadline -lhistory


LIBFT = libft/libft.a

SRCS_DIR = ./srcs/
SRCS_LIST = main.c \
	signal.c \
	

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))


all: $(NAME)
		
$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(LINK) -o $(NAME)
	
re: fclean all
	
clean:
	make clean -C libft


fclean:   	
	make fclean -C libft
	rm -rf $(NAME) 		


.PHONY: all re clean fclean

.SILENT:

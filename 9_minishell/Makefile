# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femorell <femorell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:04:32 by sum               #+#    #+#              #
#    Updated: 2024/01/26 00:20:32 by femorell         ###   ########.fr        #
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
	check.c \
	parsing.c \
	utils.c \
	update.c \
	expansion.c \
	ft_cd.c \
	ft_env.c \
	ft_pwd.c \
	ft_echo.c \
	ft_exit.c \
	ft_unset.c \
	ft_export.c

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

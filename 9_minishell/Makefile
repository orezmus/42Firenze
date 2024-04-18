# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <sum@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:04:32 by sum               #+#    #+#              #
#    Updated: 2024/01/30 18:39:04 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror 
LINK = -lreadline -lhistory


LIBFT = libft/libft.a

SRCS_DIR = ./srcs/
SRCS_LIST = minishell.c \
	prompt.c \
	prompt_utils.c \
	envp.c \
	signal.c \
	check.c \
	parsing.c \
	list_cmd.c \
	utils.c \
	update.c \
	error.c \
	exec_cmd.c \
	builtin.c \
	execute.c \
	redirect.c \
	expansion.c \
	heredoc.c \
	heredoc_utils.c \
	ft_cd.c \
	ft_env.c \
	ft_pwd.c \
	ft_echo.c \
	ft_exit.c \
	ft_unset.c \
	ft_export.c \
	ft_cd_utils.c \
	ft_cd_utils2.c \

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



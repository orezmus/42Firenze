# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femorell <femorell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 13:49:02 by sum               #+#    #+#              #
#    Updated: 2024/03/05 18:27:56 by femorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lm -lX11 -lXext
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS_LIST = main.c \
            init.c \
            game_free.c \
            hook.c \
            map_check.c \
            map_info.c \
            map_color.c \
            map_read.c \
            map_render.c \
            ray_init.c \
            draw_init.c \
            player_act.c \
            utils.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:.c=.o))

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) $(LDFLAGS) -o $(NAME)

re: fclean all

clean:
	make clean -C libft
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

.PHONY: all re clean fclean

.SILENT:

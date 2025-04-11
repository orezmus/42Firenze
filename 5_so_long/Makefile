# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femorell <femorell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 15:24:36 by femorell          #+#    #+#              #
#    Updated: 2023/03/17 15:44:24 by femorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a
MINILIBX = minilibx-linux/libmlx.a

FLAGS = -no-pie -Wall -Werror -Wextra -g
LINKS = -lm -lX11 -lXext

SRC := src/main.c \
	src/hook.c \
	src/game_init.c \
	src/map_read.c \
	src/map_check.c \
	src/map_check2.c \
	src/map_render.c \
	src/sprite_init.c \
	src/coin_init.c \
	src/exit_init.c \
	src/player_act.c \
	src/player_draw.c \
	src/player_draw2.c \
	src/player_init.c \
	src/image.c \
	src/map_frame.c \
	src/sprite_load_top.c \
	src/game_free.c

SRC_BONUS := src_bonus/main.c \
	src_bonus/hook.c \
	src_bonus/game_init.c \
	src_bonus/map_read.c \
	src_bonus/map_check.c \
	src_bonus/map_check2.c \
	src_bonus/map_render.c \
	src_bonus/sprite_init.c \
	src_bonus/coin_init.c \
	src_bonus/exit_init.c \
	src_bonus/player_act.c \
	src_bonus/player_draw.c \
	src_bonus/player_draw2.c \
	src_bonus/player_init.c \
	src_bonus/player_status.c \
	src_bonus/image.c \
	src_bonus/map_frame.c \
	src_bonus/sprite_load_top.c \
	src_bonus/monster_create.c \
	src_bonus/monster_draw.c \
	src_bonus/monster_event.c \
	src_bonus/monster_init.c \
	src_bonus/game_free.c \
	src_bonus/cloud_create.c

all: $(NAME)

$(NAME): libcomp comp

bonus: libcomp
	gcc $(FLAGS) $(SRC_BONUS) $(MINILIBX) $(LIBFT) $(FT_PRINTF) $(LINKS) -o $(NAME)_bonus

libcomp:
		@make -C libft
		@make -C libft/ft_printf
	
comp:
	gcc $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(FT_PRINTF) $(LINKS) -o $(NAME)
            
libclean:
		@make clean -C libft
		@make clean -C libft/ft_printf
		
clean:		libclean

libfclean:
		@make fclean -C libft
		@make fclean -C libft/ft_printf

fclean:   	clean libfclean
		rm -rf $(NAME) $(NAME)_bonus
		
re: clean all

.PHONY: all re clean fclean bonus maps

.SILENT:

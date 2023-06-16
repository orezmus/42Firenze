# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:54:27 by sum               #+#    #+#              #
#    Updated: 2023/02/07 17:54:32 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
PF = libft/ft_printf/libftprintf.a

FLAGS = -no-pie -Wall -Werror -Wextra -g
LINKS = -lm -lX11 -lXext

SRCS := srcs/main.c \
	srcs/hook.c \
	srcs/game_init.c \
	srcs/game_free.c \
	srcs/map_read.c \
	srcs/map_check.c \
	srcs/map_render.c \
	srcs/map_create.c \
	srcs/map_frame.c \
	srcs/coin_init.c \
	srcs/exit_init.c \
	srcs/player_act.c \
	srcs/player_draw.c \
	srcs/player_draw2.c \
	srcs/player_init.c \
	srcs/image.c \
	srcs/sprite_load_top.c \

SRCS_BNS := srcs_bonus/main.c \
	srcs_bonus/hook.c \
	srcs_bonus/game_init.c \
	srcs_bonus/game_free.c \
	srcs_bonus/map_read.c \
	srcs_bonus/map_check.c \
	srcs_bonus/map_render.c \
	srcs_bonus/map_create.c \
	srcs_bonus/map_frame.c \
	srcs_bonus/coin_init.c \
	srcs_bonus/exit_init.c \
	srcs_bonus/player_act.c \
	srcs_bonus/player_draw.c \
	srcs_bonus/player_draw2.c \
	srcs_bonus/player_init.c \
	srcs_bonus/player_status.c \
	srcs_bonus/image.c \
	srcs_bonus/sprite_load_top.c \
	srcs_bonus/monster_create.c \
	srcs_bonus/monster_draw.c \
	srcs_bonus/monster_event.c \
	srcs_bonus/monster_init.c


all: $(NAME)

$(NAME):  libcomp comp

bonus:	libcomp
	gcc $(FLAGS) $(SRCS_BNS) $(MINILIBX) $(LIBFT) $(PF) $(LINKS) -o $(NAME)_bonus
		
libcomp:
		@make -C libft
		@make -C libft/ft_printf
	
comp:
	gcc $(FLAGS) $(SRCS) $(MINILIBX) $(LIBFT) $(PF) $(LINKS) -o $(NAME)
	
            
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

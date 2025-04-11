/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:26:09 by femorell          #+#    #+#             */
/*   Updated: 2023/03/17 11:58:08 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define TRUE			0
# define FALSE			1

# define LEFT 			1
# define RIGHT 			2

# define TILE_SIZE		32
# define NB 			16

# define WALL			'1' 
# define FLOOR			'0'
# define COIN			'C'
# define PLAYER			'P'
# define EXIT			'E'
# define FRAME			'F'

# define W 				119
# define ARROW_UP 		65362
# define S				115
# define ARROW_DOWN		65364
# define A 				97
# define ARROW_LEFT		65361
# define D 				100
# define ARROW_RIGHT	65363
# define E				101
# define N_ZERO			65438

# define ESC	 		65307

# define SHADOW_XPM		"assets/player/shadow"
# define RFRAME_XPM		"assets/wall/frame/rframe"
# define LFRAME_XPM		"assets/wall/frame/lframe"
# define CFRAME_XPM		"assets/wall/frame/cframe"
# define WALL_XPM		"assets/wall/wall"
# define FLOOR_XPM		"assets/other/floor"
# define COIN_XPM		"assets/coin/coin"
# define EXIT_XPM		"assets/exit/exit"
# define PLAYER_XPM		"assets/player/dino"

typedef struct s_image {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}		t_image;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_player {
	t_image		*img;
	t_vector	pos;
	int			ac[4];
	int			a[2];
	int			b[2];
	int			c[2];
	int			d[2];
	int			hp;
	int			life;
	int			direction;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	t_vector	size;
	char		*buffer;
	t_vector	pos;
	int			move;
	int			c;
	int			e;
	int			p;
	t_image		*shadow;
	t_image		*cframe;
	t_image		*lframe;
	t_image		*rframe;
	t_image		*sprites;
	t_image		*exit;
	t_image		*floor;
	t_image		*coin;
	t_player	*player;
	t_alloc		*alloc;
	t_alloc		*img_alloc;
}		t_game;

void		exit_error(int i, char *msg, t_game *game);

int			kill_hook(t_game *game);
int			keydown_hook(int keycode, t_game *game);
int			keyup_hook(int keycode, t_game *game);

int			player_actcode(int keycode);
void		player_act(int keycode, t_game *game);
void		player_disact(int keycode, t_game *game);

void		game_init(t_game *game);

void		map_read(t_game *game, char *filename);
void		map_check(t_game *game, char *filename);
void		map_render(t_game *game);
void		map_check_parameter(t_game *game);
int			map_count_parameter(t_game *game);

void		init_mlx(t_game *game);
void		init_save_sprites(t_game *game);

void		sprite_init_top(t_game *game, t_image *map);

void		coin_init(t_game *game, t_image *map);

void		exit_init(t_game *game, t_image *map);

void		create_map(t_game *game);

int			create_trgb(int t, int r, int g, int b);
void		construct_image(char *buffer, t_vector pos,
				t_image image2, t_image image);
t_image		generate_image(t_game game, char *path, t_alloc **alloc);
void		shadow(char *buffer, t_vector pos, t_image image2, t_image image);

char		**map_frame(t_game *game, char **map, t_alloc **alloc);
int			frame_anim(t_game *game);

void		player_init(t_game *game, t_image *map);
void		player_draw(t_game *game, t_image *map);
int			player_hurt_img(int *last_img, t_game *game);
int			player_attack_img(int *last_img, t_game *game);
int			player_walk_img(int *last_img, t_game *game);
int			player_stay_img(int *last_img, t_game *game);
void		player_status(t_game *game);

void		free_game(t_game *game);

char		**map_init(char *filename);
void		ft_free_matrix(char **matrix);
int			ft_pathcheck(t_game *game, char *filename);

#endif

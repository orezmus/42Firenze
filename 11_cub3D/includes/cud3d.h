/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cud3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:56 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 17:34:14 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUD3D_H
# define CUD3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define SPEED		0.05
# define TRUE		0
# define FALSE		1

# define TEX_W		64
# define TEX_H		64
# define SCREEN_W	1280
# define SCREEN_H	720

# define NO		0
# define SO 		1
# define EA 		2
# define WE		3

# define FLOOR		5
# define CEILING	6

# define W		119
# define S		115
# define A		97
# define D		100
# define ARROW_LEFT	65361
# define ARROW_RIGHT	65363

# define ESC		65307

typedef struct s_image
{
	void	*image;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}		t_image;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}		t_player;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perp_wall_dist;
	double		tex_pos;
	double		wall_x;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	int			tex_x;
	int			tex_y;
}		t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**cub;
	char		**map;
	int			**wall;
	int			size;
	int			x;
	int			y;
	int			p;
	int			info;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_right;
	int			key_left;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			floor;
	int			ceiling;
	t_image		texture;	
	t_player	*player;
}		t_game;

int		kill_hook(t_game *game);
int		keydown_hook(int keycode, t_game *game);
int		keyup_hook(int keycode, t_game *game);

void	map_check(t_game *game);
void	map_read(t_game *game, char *filename);
void	map_info(t_game *game, char **line, int *i);
void	map_render(t_game *game);

void	map_background(t_game *game, char *line, int info);

void	data_init(t_game *game);
void	game_init(t_game *game);

void	ray_init(t_game *game, t_ray *ray, int x);
void	draw_init(t_game *game, t_ray *ray, int x);

void	player_act(t_game *game);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(int c);
int		remove_space(char *line);
char	*strjoin_free(char *s1, char *s2);
void	free_split(char **str);

void	exit_error(int er, char *msg, char *str, t_game *game);
void	free_game(t_game *game);
void	free_malloc(t_game *game);

#endif

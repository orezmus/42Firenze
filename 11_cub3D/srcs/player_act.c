/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:36:45 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	rotate_vector(t_game *game, double speed)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->player->dir_x;
	oldplane_x = game->player->plane_x;
	game->player->dir_x = \
		game->player->dir_x * cos(speed) - game->player->dir_y * sin(speed);
	game->player->dir_y = \
		olddir_x * sin(speed) + game->player->dir_y * cos(speed);
	game->player->plane_x = \
		game->player->plane_x * cos(speed) - game->player->plane_y * sin(speed);
	game->player->plane_y = \
		oldplane_x * sin(speed) + game->player->plane_y * cos(speed);
}

void	move_vertical(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->key_w == 1)
	{
		if (game->map[(int)(p->pos_y + p->dir_y * SPEED)][(int)p->pos_x] != '1')
			p->pos_y += p->dir_y * SPEED;
		if (game->map[(int)p->pos_y][(int)(p->pos_x + p->dir_x * SPEED)] != '1')
			p->pos_x += p->dir_x * SPEED;
	}
	if (game->key_s == 1)
	{
		if (game->map[(int)(p->pos_y - p->dir_y * SPEED)][(int)p->pos_x] != '1')
			p->pos_y -= p->dir_y * SPEED;
		if (game->map[(int)p->pos_y][(int)(p->pos_x - p->dir_x * SPEED)] != '1')
			p->pos_x -= p->dir_x * SPEED;
	}
}

void	move_horizontal(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->key_a == 1)
	{
		if (game->map[(int)(p->pos_y - p->dir_x * SPEED)][(int)p->pos_x] != '1')
			p->pos_y -= p->dir_x * SPEED;
		if (game->map[(int)p->pos_y][(int)(p->pos_x + p->dir_y * SPEED)] != '1')
			p->pos_x += p->dir_y * SPEED;
	}
	if (game->key_d == 1)
	{
		if (game->map[(int)(p->pos_y + p->dir_x * SPEED)][(int)p->pos_x] != '1')
			p->pos_y += p->dir_x * SPEED;
		if (game->map[(int)p->pos_y][(int)(p->pos_x - p->dir_y * SPEED)] != '1')
			p->pos_x -= p->dir_y * SPEED;
	}
}

void	player_act(t_game *game)
{
	move_vertical(game);
	move_horizontal(game);
	if (game->key_right == 1)
		rotate_vector(game, SPEED);
	if (game->key_left == 1)
		rotate_vector(game, -SPEED);
}

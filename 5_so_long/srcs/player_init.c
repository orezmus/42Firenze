/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:17:23 by sum               #+#    #+#             */
/*   Updated: 2025/04/11 11:37:31 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_count(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->pos.x + NB - 1) != p->a[0] || (p->pos.y + NB - 1) != p->a[1])
	{
		game->move++;
	}
}

void	player_move_x(t_game *game)
{
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (p->ac[0] == 1 || p->ac[1] == 1 || p->ac[2] == 1)
	{
		if (m[p->a[1] / 32][(p->a[0] - 1) / 32] != WALL &&
		m[p->c[1] / 32][(p->c[0] - 1) / 32] != WALL)
		{
			p->direction = LEFT;
			p->pos.x -= 1;
		}
	}
	else if (p->ac[0] == 3 || p->ac[1] == 3 || p->ac[2] == 3)
	{
		if (m[p->b[1] / 32][(p->b[0] + 1) / 32] != WALL &&
		m[p->d[1] / 32][(p->d[0] + 1) / 32] != WALL)
		{
			p->direction = RIGHT;
			p->pos.x += 1;
		}	
	}
}

void	player_move_y(t_game *game)
{
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (p->ac[0] == 2 || p->ac[1] == 2 || p->ac[2] == 2)
	{
		if (m[(p->c[1] + 1) / 32][p->c[0] / 32] != WALL &&
		m[(p->d[1] + 1) / 32][p->d[0] / 32] != WALL)
			p->pos.y += 1;
	}
	else if (p->ac[0] == 4 || p->ac[1] == 4 || p->ac[2] == 4)
	{
		if (m[(p->a[1] - 1) / 32][p->a[0] / 32] != WALL &&
		m[(p->b[1] - 1) / 32][p->b[0] / 32] != WALL)
			p->pos.y -= 1;
	}
}

void	player_position(t_game *game)
{
	t_player	*p;

	p = game->player;
	p->a[0] = p->pos.x + NB - 1;
	p->a[1] = p->pos.y + NB - 1;
	p->b[0] = p->pos.x + NB;
	p->b[1] = p->pos.y + NB - 1;
	p->c[0] = p->pos.x + NB - 1;
	p->c[1] = p->pos.y + NB;
	p->d[0] = p->pos.x + NB;
	p->d[1] = p->pos.y + NB;
}

void	player_init(t_game *game, t_image *map)
{
	player_position(game);
	player_move_x(game);
	player_move_y(game);
	player_draw(game, map);
	player_move_count(game);
}

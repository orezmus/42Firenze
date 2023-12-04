/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:31:19 by sum               #+#    #+#             */
/*   Updated: 2023/02/06 20:31:20 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	monster_wall(int i, int j, t_game *game)
{
	if (game->map[i][j] != WALL && game->map[i][j] != EXIT
		&& game->map[i][j] != COIN)
		return (1);
	return (0);
}

static int	monster_way(int i, t_monster *mon, t_game *game)
{
	if (i == 0 && (monster_wall(mon->a[1] / TILE_SIZE,
				(mon->a[0] - 1) / TILE_SIZE, game)
			&& monster_wall(mon->c[1] / TILE_SIZE,
				(mon->c[0] - 1) / TILE_SIZE, game)))
		return (TRUE);
	else if (i == 1 && (monster_wall((mon->c[1] + 1) / TILE_SIZE,
				mon->c[0] / TILE_SIZE, game)
			&& monster_wall((mon->d[1] + 1) / TILE_SIZE,
				mon->d[0] / TILE_SIZE, game)))
		return (TRUE);
	else if (i == 2 && (monster_wall(mon->b[1] / TILE_SIZE,
				(mon->b[0] + 1) / TILE_SIZE, game)
			&& monster_wall(mon->d[1] / TILE_SIZE,
				(mon->d[0] + 1) / TILE_SIZE, game)))
		return (TRUE);
	else if (i == 3 && (monster_wall((mon->a[1] - 1) / TILE_SIZE,
				mon->a[0] / TILE_SIZE, game)
			&& monster_wall((mon->b[1] - 1) / TILE_SIZE,
				mon->b[0] / TILE_SIZE, game)))
		return (TRUE);
	return (FALSE);
}

static void	monster_moving(int dir, t_monster *mon)
{
	if (dir == 0)
	{
		mon->direction = LEFT;
		mon->pos.x -= 1;
	}
	else if (dir == 1)
		mon->pos.y += 1;
	else if (dir == 2)
	{
		mon->direction = RIGHT;
		mon->pos.x += 1;
	}
	else if (dir == 3)
		mon->pos.y -= 1;
}

static int	monster_move(t_monster *mon, t_game *game)
{
	if (mon->inter < 120 && monster_way(mon->code, mon, game) == TRUE)
		monster_moving(mon->code, mon);
	else
	{
		if (mon->inter > 119)
			mon->inter = 0;
		mon->code = rand() % 4;
	}
	mon->inter++;
	return (0);
}

void	monster_init(t_game *game, t_image *map)
{
	t_list		*mons;
	t_monster	*mon;

	mons = game->monsters;
	while (mons)
	{
		mon = ((t_monster *)mons->content);
		monster_position(mon);
		if (mon->move == 1)
			monster_move(mon, game);
		mons = mons->next;
	}
	monster_event(game);
	monster_draw(game, map);
}

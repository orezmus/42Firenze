/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:13:10 by sum               #+#    #+#             */
/*   Updated: 2023/02/06 18:13:13 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	monster_position(t_monster *mon)
{
	mon->a[0] = mon->pos.x + NB - 1;
	mon->a[1] = mon->pos.y + NB - 1;
	mon->b[0] = mon->pos.x + NB;
	mon->b[1] = mon->pos.y + NB - 1;
	mon->c[0] = mon->pos.x + NB - 1;
	mon->c[1] = mon->pos.y + NB;
	mon->d[0] = mon->pos.x + NB;
	mon->d[1] = mon->pos.y + NB;
}

void	monster_create(t_game *game, t_vector it)
{
	t_monster	*mon;

	mon = ft_calloc(sizeof(t_monster), 1);
	if (mon == NULL)
		exit_error(0, "Invalid Map. Allocation error.", game);
	mon->pos.x = it.x * TILE_SIZE;
	mon->pos.y = it.y * TILE_SIZE;
	mon->life = 1;
	mon->inter = 0;
	mon->damage = -4;
	mon->code = (it.x + it.y) % 4;
	mon->direction = LEFT;
	mon->move = 1;
	if (game->monsters == NULL)
		game->monsters = ft_lstnew(mon);
	else
		ft_lstadd_front(&game->monsters, ft_lstnew(mon));
}

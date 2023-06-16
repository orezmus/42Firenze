/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:03:14 by sum               #+#    #+#             */
/*   Updated: 2023/02/06 22:03:15 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	monster_dead_img(t_monster *mon)
{
	if (mon->la != 2)
		mon->img = 0;
	mon->la = 2;
	if (mon->direction == LEFT)
	{
		if (mon->img > 44 && mon->img < 49)
			mon->img++;
		else if (mon->img != 49)
			mon->img = 45;
	}
	else
	{
		if (mon->img > 19 && mon->img < 24)
			mon->img++;
		else if (mon->img != 24)
			mon->img = 20;
	}
	if (mon->img == 49 || mon->img == 24)
		mon->damage--;
	return (mon->img);
}

static int	monster_walk_img(t_monster *mon)
{
	if (mon->la != 1)
		mon->img = 0;
	mon->la = 1;
	if (mon->direction == LEFT)
	{
		if (mon->img > 24 && mon->img < 45)
			mon->img++;
		else
			mon->img = 25;
	}
	else
	{
		if (mon->img > -1 && mon->img < 20)
			mon->img++;
		else
			mon->img = 0;
	}
	return (mon->img);
}

static int	monster_img(t_monster *mon)
{
	if (mon->damage != -5)
	{
		if (mon->damage > -4)
			return (monster_dead_img(mon));
		else
			return (monster_walk_img(mon));
	}
	return (0);
}

void	monster_anim(t_game *game, t_monster *mon, t_image *map)
{	
	if (mon->img_inter == 4)
	{
		mon->img_inter = 0;
		monster_img(mon);
	}
	else
		mon->img_inter++;
	shadow(game->buffer, mon->pos, *map, game->smonster[mon->img]);
	construct_image(game->buffer, mon->pos, *map, game->m_img[mon->img]);
}

void	monster_draw(t_game *game, t_image *map)
{
	t_list		*mons;
	t_monster	*mon;

	mons = game->monsters;
	while (mons)
	{
		mon = (t_monster *)mons->content;
		if (mon->life == 1 || mon->damage > 0)
			monster_anim(game, mon, map);
		mons = mons->next;
	}
}

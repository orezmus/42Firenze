/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:42:10 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 13:42:12 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	coin_eaten(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->map[p->a[1] / 32][p->a[0] / 32] == COIN)
	{
		game->map[p->a[1] / 32][p->a[0] / 32] = FLOOR;
		game->c--;
	}
	else if (game->map[p->b[1] / 32][p->b[0] / 32] == COIN)
	{
		game->map[p->b[1] / 32][p->b[0] / 32] = FLOOR;
		game->c--;
	}	
	else if (game->map[p->c[1] / 32][p->c[0] / 32] == COIN)
	{
		game->map[p->c[1] / 32][p->c[0] / 32] = FLOOR;
		game->c--;
	}
	else if (game->map[p->d[1] / 32][p->d[0] / 32] == COIN)
	{
		game->map[p->d[1] / 32][p->d[0] / 32] = FLOOR;
		game->c--;
	}
}

void	coin_draw(t_game *game, t_image *map)
{	
	static int	num_img;
	static int	img_inter;

	if (img_inter > game->c * 5)
	{
		img_inter = 0;
		if (num_img < 3)
			num_img++;
		else
			num_img = 0;
	}
	else
		img_inter++;
	construct_image(game->buffer, game->pos, *map, game->coin[num_img]);
}

static void	coin_load(t_game *game, t_image *map)
{
	t_vector	it;

	it.y = 0;
	while (it.y < game->size.y)
	{
		it.x = 0;
		while (it.x < game->size.x)
		{
			if (game->map[it.y][it.x] == COIN)
			{
				game->pos.y = it.y * TILE_SIZE;
				game->pos.x = it.x * TILE_SIZE;
				coin_draw(game, map);
			}
			it.x++;
		}
		it.y++;
	}
}	

void	coin_init(t_game *game, t_image *map)
{
	coin_load(game, map);
	coin_eaten(game);
}

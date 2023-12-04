/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:11:31 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 10:19:21 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	wall_draw(t_game *game, t_vector it, t_image *map)
{
	if (it.y == 0 && it.x == 0)
		construct_image(game->buffer, game->pos, *map, game->sprites[1]);
	else if (it.y == 0 && it.x == game->size.x - 1)
		construct_image(game->buffer, game->pos, *map, game->sprites[2]);
	else if (it.y == game->size.y - 1 && it.x == 0)
		construct_image(game->buffer, game->pos,
			*map, game->lframe[frame_anim(game)]);
	else if (it.y == game->size.y - 1 && it.x == game->size.x - 1)
		construct_image(game->buffer, game->pos,
			*map, game->rframe[frame_anim(game)]);
	else if (it.y == 0 && it.x != 0)
		construct_image(game->buffer, game->pos, *map, game->sprites[5]);
	else if (it.y != 0 && it.x == game->size.x - 1)
		construct_image(game->buffer, game->pos, *map, game->sprites[6]);
	else if (it.y == game->size.y - 1 && it.x != 0)
		construct_image(game->buffer, game->pos,
			*map, game->cframe[frame_anim(game)]);
	else if (it.y != 0 && it.x == 0)
		construct_image(game->buffer, game->pos, *map, game->sprites[8]);
}

void	sprite_load2(t_game *game, t_vector it, t_image *map)
{
	if (game->map[it.y][it.x] == WALL)
		construct_image(game->buffer, game->pos, *map, game->sprites[0]);
}

void	sprite_load(t_game *game, t_vector it, t_image *map)
{
	if (game->map[it.y][it.x] == FRAME)
		wall_draw(game, it, map);
	else if (game->map[it.y][it.x] == WALL || game->map[it.y][it.x] == FLOOR
		|| game->map[it.y][it.x] == PLAYER || game->map[it.y][it.x] == COIN
		|| game->map[it.y][it.x] == MONSTER)
		construct_image(game->buffer, game->pos, *map, game->floor[0]);
	else if (game->map[it.y][it.x] == FLOWER)
		construct_image(game->buffer, game->pos, *map, game->flower[0]);
	else if (game->map[it.y][it.x] == FLOWER2)
		construct_image(game->buffer, game->pos, *map, game->flower[1]);
}

void	sprite_init(t_game *game, t_image *map)
{
	t_vector	it;

	it.y = 0;
	while (it.y < game->size.y)
	{
		it.x = 0;
		while (it.x < game->size.x)
		{
			game->pos.x = it.x * TILE_SIZE;
			game->pos.y = it.y * TILE_SIZE;
			sprite_load(game, it, map);
			sprite_load2(game, it, map);
			it.x++;
		}
		it.y++;
	}
}

void	map_create(t_game *game)
{
	t_image		map;

	map.image = mlx_new_image(game->mlx, (game->size.x + game->size.y)
			* TILE_SIZE, (game->size.y + game->size.x) * TILE_SIZE);
	map.width = (game->size.x + game->size.y) * TILE_SIZE;
	map.height = (game->size.y + game->size.x) * TILE_SIZE;
	game->buffer = mlx_get_data_addr(map.image, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	sprite_init(game, &map);
	coin_init(game, &map);
	exit_init(game, &map);
	monster_init(game, &map);
	player_init(game, &map);
	sprite_init_top(game, &map);
	mlx_put_image_to_window(game->mlx, game->win, map.image, 0, 0);
	mlx_destroy_image(game->mlx, map.image);
}

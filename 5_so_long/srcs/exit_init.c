/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:14 by sum               #+#    #+#             */
/*   Updated: 2023/02/09 16:19:15 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	exit_finish(t_game *game, t_image *map)
{
	t_player	*p;
	static int	i;

	p = game->player;
	if (game->map[p->a[1] / 32][p->a[0] / 32] == EXIT ||
		game->map[p->b[1] / 32][p->b[0] / 32] == EXIT ||
		game->map[p->c[1] / 32][p->c[0] / 32] == EXIT ||
		game->map[p->d[1] / 32][p->d[0] / 32] == EXIT)
	{
		if (game->c == 0)
		{
			mlx_destroy_image(game->mlx, map->image);
			free_game(game);
			exit_error(0, "SUCCESS! CONGRATULATION!", game);
		}
		else if (i == 0)
		{
			i = 1;
			printf("You should eat all the coins!\n");
		}
	}
	else
		i = 0;
}	

int	exit_draw2(t_game *game, int num_img)
{
	if (game->c != 0)
	{
		if (num_img < 4)
			num_img++;
		else
			num_img = 0;
	}
	else
	{
		if (num_img == 3 || num_img == 6)
			num_img = 6;
		if (num_img == 5)
			num_img = 0;
		else if (num_img > 3 && num_img < 5)
			num_img++;
		else if (num_img < 3)
			num_img++;
	}
	return (num_img);
}

void	exit_draw(t_game *game, t_image *map)
{
	static int	num_img;
	static int	img_inter;

	if (img_inter == 10)
	{
		img_inter = 0;
		num_img = exit_draw2(game, num_img);
	}
	else
		img_inter++;
	construct_image(game->buffer, game->pos, *map, game->exit[num_img]);
}

static void	exit_load(t_game *game, t_image *map)
{
	t_vector	it;

	it.y = 0;
	while (it.y < game->size.y)
	{
		it.x = 0;
		while (it.x < game->size.x)
		{
			if (game->map[it.y][it.x] == EXIT)
			{
				game->pos.y = it.y * TILE_SIZE;
				game->pos.x = it.x * TILE_SIZE;
				exit_draw(game, map);
			}
			it.x++;
		}
		it.y++;
	}
}

void	exit_init(t_game *game, t_image *map)
{
	exit_load(game, map);
	exit_finish(game, map);
}

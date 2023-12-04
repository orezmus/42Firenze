/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:57:13 by sum               #+#    #+#             */
/*   Updated: 2023/01/20 13:57:14 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*save_sprites(int num, char *path, t_game *game)
{
	int		i;
	char	*p;
	char	*temp;
	t_image	*sprites;

	i = 0;
	sprites = ft_malloc(sizeof(t_image) * num, &game->alloc);
	if (!sprites)
		return (NULL);
	while (i < num)
	{
		temp = ft_itoa(i);
		p = ft_strjoin(path, temp);
		free(temp);
		temp = p;
		p = ft_strjoin(temp, ".xpm");
		free(temp);
		sprites[i] = generate_image(*game, p, &game->img_alloc);
		if (!sprites[i].image)
			return (NULL);
		i++;
		free(p);
	}
	return (sprites);
}

void	init_save_sprites(t_game *game)
{
	game->shadow = save_sprites(1, SHADOW_XPM, game);
	game->lframe = save_sprites(2, LFRAME_XPM, game);
	game->cframe = save_sprites(2, CFRAME_XPM, game);
	game->rframe = save_sprites(2, RFRAME_XPM, game);
	game->sprites = save_sprites(10, WALL_XPM, game);
	game->exit = save_sprites(7, EXIT_XPM, game);
	game->floor = save_sprites(1, FLOOR_XPM, game);
	game->coin = save_sprites(4, COIN_XPM, game);
	game->player->img = save_sprites(34, PLAYER_XPM, game);
}

void	init_mlx(t_game *game)
{
	if (game->mlx == NULL)
		exit_error(0, "Error in mlx. Try again.", game);
	game->win = mlx_new_window(game->mlx, game->size.x * TILE_SIZE,
			game->size.y * TILE_SIZE, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		exit_error(0, "Failed to create the window.", game);
	}
}

void	map_check_parameter(t_game *game)
{
	t_vector	it;

	it.y = 0;
	game->player->direction = RIGHT;
	while (it.y < game->size.y)
	{
		it.x = 0;
		while (it.x < game->size.x)
		{
			if (game->map[it.y][it.x] == PLAYER)
			{
				game->player->pos.x = it.x * TILE_SIZE;
				game->player->pos.y = it.y * TILE_SIZE;
			}
			it.x++;
		}
		it.y++;
	}
}

void	map_render(t_game *game)
{
	game->map = map_frame(game, game->map, &game->alloc);
	map_check_parameter(game);
	init_mlx(game);
	init_save_sprites(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:50:26 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	player_init(t_game *game)
{
	game->p = 0;
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0;
}

void	default_init(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->size = 0;
	game->info = 0;
	game->key_a = 0;
	game->key_w = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_right = 0;
	game->key_left = 0;
	game->ceiling = -1;
	game->floor = -1;
	game->map = NULL;
	game->so = NULL;
	game->no = NULL;
	game->we = NULL;
	game->ea = NULL;
}

void	data_init(t_game *game)
{
	int	i;

	game->wall = (int **)ft_calloc(sizeof(int *) * 4, 1);
	if (!game->wall)
		exit_error(1, "Malloc Error.", NULL, game);
	i = -1;
	while (++i < 4)
	{
		game->wall[i] = (int *)ft_calloc(sizeof(int) * (TEX_W * TEX_H), 1);
		if (!game->wall[i])
			exit_error(1, "Malloc Error.", NULL, game);
	}
	player_init(game);
	default_init(game);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "Cub3D");
	game->texture.image = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->texture.addr = (int *)mlx_get_data_addr(game->texture.image,
			&game->texture.bits_per_pixel, &game->texture.line_length,
			&game->texture.endian);
}

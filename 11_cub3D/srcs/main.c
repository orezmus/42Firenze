/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:08:44 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	exit_error(int er, char *msg, char *str, t_game *game)
{
	int	i;

	i = -1;
	printf("Error\n");
	printf("%s\n", msg);
	free_malloc(game);
	if (str != NULL)
		free(str);
	if (er == 1)
	{
		while (game->cub[++i])
			free(game->cub[i]);
		free(game->cub);
	}
	exit(1);
}

void	map_create(t_game *game)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < SCREEN_W)
	{
		ray_init(game, &ray, x);
		draw_init(game, &ray, x);
	}
}

static int	game_loop(t_game *game)
{
	map_create(game);
	mlx_put_image_to_window(game->mlx, game->win, game->texture.image, 0, 0);
	player_act(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("The map file is missing or wrong arguments.\n");
		exit(1);
	}
	data_init(&game);
	map_read(&game, argv[1]);
	map_check(&game);
	game_init(&game);
	map_render(&game);
	mlx_hook(game.win, 2, 1L << 0, keydown_hook, &game);
	mlx_hook(game.win, 17, 0, kill_hook, &game);
	mlx_key_hook(game.win, keyup_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

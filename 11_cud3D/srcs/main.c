/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:08:44 by sum               #+#    #+#             */
/*   Updated: 2024/01/22 15:08:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	exit_error(int er, char *msg, t_game *game)
{
	int	i;

	i = -1;
	printf("%s\n", msg);
	if (er == 1)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	exit(1);
}

/*
static int	game_loop(t_game *game)
{
	static int	inter;

	if (inter > 3000)
	{
		inter = 0;
		map_create(game);
	}
	inter++;
	return (1);
}
*/

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		exit_error(0, "The map file is missing or wrong arguments.", &game);
	game.mlx = mlx_init();
	map_read(&game, argv[1]);
	map_check(&game);
	printf("success");
	/*
	game_init(&game);
	map_render(&game);
	mlx_hook(game.win, 2, 1L << 0, keydown_hook, &game);
	mlx_hook(game.win, 17, 0, kill_hook, &game);
	mlx_key_hook(game.win, keyup_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);*/
	return (0);
}

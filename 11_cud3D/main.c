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


int	main(int argc, chra **argv)
{
	t_game	game;
	
	if (argc != 2)
		exit_error(0, "The map file is missing or wrong arguments.", &game);
	map_read(&game, argv[1]);
	map_check(&game);

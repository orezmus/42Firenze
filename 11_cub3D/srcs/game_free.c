/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:15:19 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	free_malloc(t_game *game)
{
	int	i;

	i = -1;
	free(game->player);
	while (++i < 4)
		free(game->wall[i]);
	free(game->wall);
	free(game->map);
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->ea)
		free(game->ea);
	if (game->we)
		free(game->we);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	free_malloc(game);
	while (game->cub[++i])
		free(game->cub[i]);
	free(game->cub);
	mlx_destroy_image(game->mlx, game->texture.image);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

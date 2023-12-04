/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:50 by sum               #+#    #+#             */
/*   Updated: 2023/02/07 15:34:51 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->shadow = NULL;
	game->sprites = NULL;
	game->rframe = NULL;
	game->lframe = NULL;
	game->cframe = NULL;
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->img = NULL;
	game->coin = NULL;
	game->exit = NULL;
	game->floor = NULL;
	game->flower = NULL;
	game->monsters = NULL;
	game->smonster = NULL;
}

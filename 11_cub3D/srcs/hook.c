/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:35:18 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

int	kill_hook(t_game *game)
{
	free_game(game);
	exit(0);
}

int	keydown_hook(int keycode, t_game *game)
{
	if (keycode == A)
		game->key_a = 1;
	else if (keycode == S)
		game->key_s = 1;
	else if (keycode == D)
		game->key_d = 1;
	else if (keycode == W)
		game->key_w = 1;
	else if (keycode == ARROW_LEFT)
		game->key_left = 1;
	else if (keycode == ARROW_RIGHT)
		game->key_right = 1;
	return (0);
}

int	keyup_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		kill_hook(game);
	else if (keycode == A)
		game->key_a = 0;
	else if (keycode == S)
		game->key_s = 0;
	else if (keycode == D)
		game->key_d = 0;
	else if (keycode == W)
		game->key_w = 0;
	else if (keycode == ARROW_LEFT)
		game->key_left = 0;
	else if (keycode == ARROW_RIGHT)
		game->key_right = 0;
	return (0);
}

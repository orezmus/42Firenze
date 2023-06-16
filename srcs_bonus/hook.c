/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:33:43 by sum               #+#    #+#             */
/*   Updated: 2023/02/06 15:33:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	kill_hook(t_game *game)
{
	free_game(game);
	exit(0);
}

int	keydown_hook(int keycode, t_game *game)
{
	player_act(keycode, game);
	return (0);
}

int	keyup_hook(int keycode, t_game *game)
{
	if (keycode != ESC)
		player_disact(keycode, game);
	else
		kill_hook(game);
	return (0);
}

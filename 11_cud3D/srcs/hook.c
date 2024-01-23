/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:35:18 by sum               #+#    #+#             */
/*   Updated: 2024/01/23 13:35:21 by sum              ###   ########.fr       */
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

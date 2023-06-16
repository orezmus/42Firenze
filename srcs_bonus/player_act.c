/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:02:04 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 16:02:05 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	player_actcode(int keycode)
{
	int	action;

	action = 0;
	if (keycode == A || keycode == ARROW_LEFT)
		action = 1;
	else if (keycode == S || keycode == ARROW_DOWN)
		action = 2;
	else if (keycode == D || keycode == ARROW_RIGHT)
		action = 3;
	else if (keycode == W || keycode == ARROW_UP)
		action = 4;
	else if (keycode == E || keycode == N_ZERO)
		action = 5;
	return (action);
}

void	player_act(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (player_actcode(keycode) != 5)
	{
		if (p->ac[0] == 0 || p->ac[0] == player_actcode(keycode))
			p->ac[0] = player_actcode(keycode);
		else if (p->ac[1] == 0 || p->ac[1] == player_actcode(keycode))
			p->ac[1] = player_actcode(keycode);
		else if (p->ac[2] == 0 || p->ac[2] == player_actcode(keycode))
			p->ac[2] = player_actcode(keycode);
	}
	else
		p->ac[3] = player_actcode(keycode);
}

void	player_disact(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == player_actcode(keycode))
		p->ac[0] = 0;
	if (p->ac[1] == player_actcode(keycode))
		p->ac[1] = 0;
	if (p->ac[2] == player_actcode(keycode))
		p->ac[2] = 0;
	if (p->ac[0] == 0 && p->ac[1] != 0)
	{
		p->ac[0] = p->ac[1];
		p->ac[1] = 0;
	}
	if (p->ac[1] == 0 && p->ac[2] != 0)
	{
		p->ac[1] = p->ac[2];
		p->ac[2] = 0;
	}
	if (p->ac[3] == player_actcode(keycode))
		p->ac[3] = 0;
}

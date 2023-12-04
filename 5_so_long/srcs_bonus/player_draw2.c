/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:53:58 by sum               #+#    #+#             */
/*   Updated: 2023/02/02 15:54:04 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	player_stay_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 1)
			i = 17;
		else if (i > 16 && i < 20)
			i++;
		else
			i = 17;
	}
	else
	{
		if (*last_img != 1)
			i = 0;
		else if (i > -1 && i < 3)
			i++;
		else
			i = 0;
	}
	*last_img = 1;
	return (i);
}

int	player_walk_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 2)
			i = 21;
		else if (i > 20 && i < 26)
			i++;
		else
			i = 21;
	}
	else
	{
		if (*last_img != 2)
			i = 4;
		else if (i > 3 && i < 10)
			i++;
		else
			i = 4;
	}
	*last_img = 2;
	return (i);
}

int	player_attack_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 3)
			i = 27;
		else if (i > 26 && i < 30)
			i++;
		else
			i = 27;
	}
	else
	{
		if (*last_img != 3)
			i = 11;
		else if (i > 10 && i < 13)
			i++;
		else
			i = 11;
	}
	*last_img = 3;
	return (i);
}

int	player_hurt_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 4)
			i = 31;
		else if (i > 30 && i < 33)
			i++;
		else
			i = 31;
	}
	else
	{
		if (*last_img != 4)
			i = 14;
		else if (i > 13 && i < 16)
			i++;
		else
			i = 14;
	}		
	*last_img = 4;
	return (i);
}

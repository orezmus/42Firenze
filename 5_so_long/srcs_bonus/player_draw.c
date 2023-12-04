/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:47 by sum               #+#    #+#             */
/*   Updated: 2023/02/02 14:22:48 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	player_img(int attack, int hurt, int *last_img, t_game *game)
{
	if (attack > 0)
		return (player_attack_img(last_img, game));
	else if (hurt > 0)
		return (player_hurt_img(last_img, game));
	else if (game->player->ac[0] == 1 || game->player->ac[0] == 2
		|| game->player->ac[0] == 3 || game->player->ac[0] == 4)
		return (player_walk_img(last_img, game));
	else
		return (player_stay_img(last_img, game));
}

void	player_anim(t_game *game, t_image *map)
{
	static int	num;
	static int	last_img;
	static int	img_inter;
	static int	attack;
	static int	hurt;

	if (game->player->ac[3] == 5)
		attack = 5;
	if (game->player->hp == 1)
		hurt = 5;
	if (img_inter == 5)
	{
		img_inter = 0;
		if (attack > 0)
			attack--;
		if (hurt > 0)
			hurt--;
		num = player_img(attack, hurt, &last_img, game);
	}
	else
		img_inter++;
	shadow(game->buffer, game->player->pos, *map, game->shadow[0]);
	construct_image(game->buffer, game->player->pos,
		*map, game->player->img[num]);
}

void	player_draw(t_game *game, t_image *map)
{
	player_anim(game, map);
}

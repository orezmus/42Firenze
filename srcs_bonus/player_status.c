/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:10 by sum               #+#    #+#             */
/*   Updated: 2023/02/14 15:04:12 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_status(t_game *game)
{
	char	*movements;
	char	*coin;
	char	*hp;
	char	*life;
	int		a;

	coin = ft_itoa(game->c);
	movements = ft_itoa(game->move);
	hp = ft_itoa(game->player->hp);
	life = ft_itoa(game->player->life);
	a = (ft_strlen(coin) - 1) * 8;
	mlx_string_put(game->mlx, game->win, 30, 12, 0xf7e8df, "coin");
	mlx_string_put(game->mlx, game->win, 63, 12, 0xf7e8df, coin);
	mlx_string_put(game->mlx, game->win, a + 78, 12, 0xf7e8df, "|");
	mlx_string_put(game->mlx, game->win, a + 93, 12, 0xf7e8df, "steps");
	mlx_string_put(game->mlx, game->win, a + 128, 12, 0xf7e8df, movements);
	mlx_string_put(game->mlx, game->win, 30, 25, 0xf7e8df, "hp");
	mlx_string_put(game->mlx, game->win, 50, 25, 0xf7e8df, hp);
	mlx_string_put(game->mlx, game->win, 70, 25, 0xf7e8df, "|");
	mlx_string_put(game->mlx, game->win, 85, 25, 0xf7e8df, "life");
	mlx_string_put(game->mlx, game->win, 120, 25, 0xf7e8df, life);
	free(movements);
	free(coin);
	free(hp);
	free(life);
}

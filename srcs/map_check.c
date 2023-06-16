/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:50 by sum               #+#    #+#             */
/*   Updated: 2023/01/20 12:49:51 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size.y)
	{
		if (ft_strlen(game->map[i]) != game->size.x)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	map_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		if (i == 0 || i == game->size.y - 1)
		{
			j = 0;
			while (j < game->size.x)
			{
				if (game->map[i][j] != WALL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != WALL ||
				game->map[i][game->size.x - 1] != WALL)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	map_count_parameter(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == COIN)
				game->c++;
			else if (game->map[i][j] == EXIT)
				game->e++;
			else if (game->map[i][j] == PLAYER)
				game->p++;
			else if (game->map[i][j] != FLOOR && game->map[i][j] != WALL)
				exit_error(1, "Invalid Map. Contents error.", game);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_check(t_game *game)
{
	game->move = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	if (map_check_rectangular(game) == FALSE)
		exit_error(1, "The map must be rectangular.", game);
	if (map_check_wall(game) == FALSE)
		exit_error(1, "The map must be surrounded by walls.", game);
	map_count_parameter(game);
	if (game->c == 0)
		exit_error(1, "Invalid Map. There are no coins.", game);
	else if (game->e != 1)
		exit_error(1, "Invalid Map. Exit quantity error.", game);
	else if (game->p != 1)
		exit_error(1, "Invalid Map. Player quantity error.", game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:36:41 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static int	map_check_blank(t_game *game, int i, int j)
{
	if (i - 1 > 0)
		if (game->map[i - 1][j] != ' ' && game->map[i - 1][j] != '1')
			return (FALSE);
	if (j - 1 > 0)
		if (game->map[i][j - 1] != ' ' && game->map[i][j - 1] != '1')
			return (FALSE);
	if (i + 1 < game->y)
		if (game->map[i + 1][j] != ' ' && game->map[i + 1][j] != '1')
			return (FALSE);
	if (j + 1 < game->x)
		if (game->map[i][j + 1] != ' ' && game->map[i][j + 1] != '1')
			return (FALSE);
	return (TRUE);
}

static int	map_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		if (i == 0 || i == game->y - 1)
		{
			while (++j < ft_strlen(game->map[i]))
			{
				if (!(game->map[i][j] == '1' || game->map[i][j] == ' '))
					return (FALSE);
			}
		}
		else
		{
			while (game->map[i][++j] == ' ')
				;
			if (!(game->map[i][j] == '1'
				&& game->map[i][ft_strlen(game->map[i]) - 1] == '1'))
				return (FALSE);
		}
	}
	return (TRUE);
}

void	map_player(t_game *game, int i, int j)
{
	game->player->pos_x = j + 0.5;
	game->player->pos_y = i + 0.5;
	if (game->map[i][j] == 'N')
	{
		game->player->dir_y = -1;
		game->player->plane_x = 0.77;
	}
	else if (game->map[i][j] == 'S')
	{
		game->player->dir_y = 1;
		game->player->plane_x = -0.77;
	}
	else if (game->map[i][j] == 'W')
	{
		game->player->dir_x = -1;
		game->player->plane_y = -0.77;
	}
	else if (game->map[i][j] == 'E')
	{
		game->player->dir_x = 1;
		game->player->plane_y = 0.77;
	}
	game->p++;
}

int	map_contents(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == ' ')
			{
				if (map_check_blank(game, i, j))
					exit_error(1, "Invalid Map. Blank founded.", NULL, game);
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				if (game->map[i][j] != 'N' && game->map[i][j] != 'S'
					&& game->map[i][j] != 'E' && game->map[i][j] != 'W')
					exit_error(1, "Invalid Map. Contents error.", NULL, game);
				map_player(game, i, j);
			}
		}
	}
	return (0);
}

void	map_check(t_game *game)
{
	if (game->info != 6)
		exit_error(1, "Map information is not enough.", NULL, game);
	if (map_check_wall(game) == FALSE)
		exit_error(1, "The map must be surrounded by walls.", NULL, game);
	map_contents(game);
	if (game->p != 1)
		exit_error(1, "Invalid Map. Player quantity error.", NULL, game);
}

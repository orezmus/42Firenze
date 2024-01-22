/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:36:41 by sum               #+#    #+#             */
/*   Updated: 2024/01/22 16:36:42 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static int	map_check_blank(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < game->y)
	{
		j = 0;
		while (game->map[i][j] == ' ')
				j++;
		while (j < ft_strlen(game->map[i])
		{
			if (!ft_isalnum(game->map[i][j])
				return (FALSE);
			j++;
		}
	return (TRUE);
}


static int	map_check_wall(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < game->y)
	{
		if (i == 0 || i == game->y - 1)
		{
			j = 0;
			while (j < ft_strlen(game->map[i] && game->map[i][j] == ' ')
				j++;
			while (j < ft_strlen(game->map[i])
			{
				if (game->map[i][j] != WALL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != 1 ||
				game->map[i][ft_strlen(game->map[i] - 1] != 1)
				return (FALSE);
		}
	}
	return (TRUE);
}
			
void	map_check(t_game *game)
{
	if (map_check_wall(game) == FALSE)
		exit_error(1, "The map must be surrounded by walls.", game);
	if (map_check_blank(game) == FALSE)
		exit_error(1, "The map has black.", game);
}

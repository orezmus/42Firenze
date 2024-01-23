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
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == ' ' || 
			!(game->map[i][j] != '0' || game->map[i][j] != '1'))
				return (FALSE);
			j++;
		}
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
		j = 0;
		if (i == 0 || i == game->y - 1)
		{
			while (j < ft_strlen(game->map[i]) && game->map[i][j] == ' ')
				j++;
			while (j < ft_strlen(game->map[i]))
			{
				if (!(game->map[i][j] == '1' || game->map[i][j] == ' '))
					return (FALSE);
				j++;
			}
		}
		else
		{
			while (j < ft_strlen(game->map[i]) && game->map[i][j] == ' ')
				j++;
			if (game->map[i][j] == 1)
			{
				while (game->map[i][j + 1] == ' ')
					j++;
				if (game->map[i][j] != 1) 
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

int	map_player(t_game *game)
{
	int	i;
	int	j;
	int	p;
	
	p = 0;
	i = -1;
	while (++i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			while (j < ft_strlen(game->map[i]) && game->map[i][j] == ' ')
				j++;
			if (game->map[i][j] != '0' || game->map[i][j] != '1')
			{
				if (game->map[i][j] == 'N')
					game->pos = N;
				else if (game->map[i][j] == 'S')
					game->pos = S;
				else if (game->map[i][j] == 'W')
					game->pos = W;
				else if (game->map[i][j] == 'E')
					game->pos = E;
				p++;
			}
			else
				exit_error(1, "Invalid Map. Contents error.", game);			
			j++;
		}
	}
	return (0);
}
		
void	map_check(t_game *game)
{
	if (game->info != 6)
		exit_error(1, "Map information is not enough.", game);
	if (map_check_wall(game) == FALSE)
		exit_error(1, "The map must be surrounded by walls.", game);
	if (map_check_blank(game) == FALSE)
		exit_error(1, "The map has blank.", game);
	map_player(game);
	if (game->p != 1)
		exit_error(1, "Invalid Map. Player quantity error.", game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:40:15 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

char	*get_info(t_game *game, char *line)
{
	char	**temp;
	char	*file;
	int		fd;

	temp = ft_split(line, ' ');
	if (!temp)
		exit_error(0, "Information Error.", NULL, game);
	if (temp[2])
	{
		free_split(temp);
		exit_error(1, "Information Error.", NULL, game);
	}
	file = ft_strdup(temp[1]);
	free_split(temp);
	fd = open(file, O_DIRECTORY);
	if (fd < 0)
		fd = open(file, O_RDONLY);
	else
		exit_error(1, "Failed to open the map image.", file, game);
	if (fd < 0)
		exit_error(1, "Failed to open the map image.", file, game);
	game->info++;
	return (file);
}

void	map_info(t_game *game, char **line, int *i)
{
	while (line[++(*i)] && game->info < 6)
	{
		if (!ft_strncmp(line[*i], "WE ", 3) && game->we == NULL)
			game->we = get_info(game, line[*i]);
		else if (!ft_strncmp(line[*i], "NO ", 3) && game->no == NULL)
			game->no = get_info(game, line[*i]);
		else if (!ft_strncmp(line[*i], "SO ", 3) && game->so == NULL)
			game->so = get_info(game, line[*i]);
		else if (!ft_strncmp(line[*i], "EA ", 3) && game->ea == NULL)
			game->ea = get_info(game, line[*i]);
		else if (!ft_strncmp(line[*i], "F ", 2) && game->floor == -1)
			map_background(game, line[*i], FLOOR);
		else if (!ft_strncmp(line[*i], "C ", 2) && game->ceiling == -1)
			map_background(game, line[*i], CEILING);
		else
			exit_error(1, "Wrong information.", NULL, game);
	}
}

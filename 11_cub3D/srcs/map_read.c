/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:06 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"		

static void	map_size(t_game *game)
{
	int	i;
	int	temp;

	i = -1;
	while (game->map[++i])
	{
		temp = game->x;
		if (temp < ft_strlen(game->map[i]))
			game->x = ft_strlen(game->map[i]);
	}
	if (game->y == 0 || game->x == 0)
		exit_error(1, "Invalid map. Map is empty.", NULL, game);
}

void	map_malloc(t_game *game, char **line, int *i)
{
	int		j;

	j = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->size - 5));
	while (line[(*i)])
	{
		game->map[j++] = line[(*i)++];
		game->y++;
	}
	game->map[j] = NULL;
}

void	map_init(t_game *game, int fd)
{
	char	*line;
	char	*temp;

	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (remove_space(line))
		{
			free(line);
			continue ;
		}
		temp = strjoin_free(temp, line);
		game->size++;
	}
	game->cub = ft_split(temp, '\n');
	free(temp);
	close(fd);
}

void	map_read(t_game *game, char *filename)
{
	int	fd;
	int	len;
	int	i;

	fd = open(filename, O_DIRECTORY);
	if (fd < 0)
		fd = open(filename, O_RDONLY);
	else
		exit_error(0, "Map should be file.", NULL, game);
	if (fd <= 0)
		exit_error(0, "Failed to open the map.", NULL, game);
	len = ft_strlen(filename);
	if (len < 4 || !ft_strnstr(&filename[len - 4], ".cub", 4))
		exit_error(0, "Map file extention is not .cub.", NULL, game);
	i = -1;
	map_init(game, fd);
	if (game->size == 0)
		exit_error(1, "Invalid map, Map is empty.", NULL, game);
	map_info(game, game->cub, &i);
	map_malloc(game, game->cub, &i);
	map_size(game);
}

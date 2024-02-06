/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:06 by sum               #+#    #+#             */
/*   Updated: 2024/01/22 15:20:08 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"		
		
static void	map_size(t_game *game, int fd)
{
	char	c;
	int	temp;

	temp = 0;
	while (read(fd, &c, 1) > 0)
	{	
		if (c == '\n')
			temp = 0;
		else
			temp++;
		if(temp > game->x)
			game->x = temp;
	}
	close(fd);
}

void	map_malloc(t_game *game, int fd)
{
	map_size(game, fd);
	if (game->y == 0 || game->x == 0)
		exit_error(0, "Invalid map. It's empty.", game);
}

	
int	map_init(t_game *game, char *filename)
{
	char	*mapping;
	char	*temp;
	int	fd;
	int	i;
	
	i = -1;
	
	fd = open(filename, O_RDONLY);
	mapping = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		game->y++;
		if (!ft_strncmp(temp, "\n", 1))
		{
			free(temp);
			continue;
		}
		if (game->info == 6)
		{
			mapping = strjoin_free(mapping, temp);
			game->y++;
		}
		else
		{
			map_info(game, temp);
			free(temp);
		}
	}
	game->map = ft_split(mapping, '\n');
	while (game->map[++i])
		printf("%d : %s \n", i, game->map[i]);
	free(mapping);
	close(fd);
	return (0);
}
		
		
void	map_read(t_game *game, char *filename)
{
	int	fd;
	int	len;

	game->x = 0;
	game->y = 0;
	game->info = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_error(0, "Failed to open the map.", game);
	len = ft_strlen(filename);
	if (len < 4 || !ft_strnstr(&filename[len - 4], ".cub", 4))
		exit_error(0, "Map file extention is not .cub.", game);
	map_init(game, filename);
	map_malloc(game, fd);
}


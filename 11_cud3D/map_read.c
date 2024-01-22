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

char	*get_info(t_game *game, char *line)
{
	char	**temp;
	int	fd;
	
	temp = ft_split(line, ' ');
	if (!temp)
		exit_error(0, "Information Error", game);
	fd = open(temp[1], O_RDONLY);
	if (fd < 0)
		exit_error(0, "Failed to open the map image.", game);
	game->info++;
	return (temp[1]);
}
	
void	map_info(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3))
		game->no = get_info(game, line);
	else if (ft_strncmp(line, "SO ", 3))
		game->so = get_info(game, line);
	else if (ft_strncmp(line, "EA ", 3))
		game->ea = get_info(game, line);
	else if (ft_strncmp(line, "WE ", 3))
		game->we = get_info(game, line);
	else if (ft_strncmp(line, "F ", 2))
		game->fcolor= = get_info(game, line);
	else if (!ft_strncmp(line, "C ", 2))
		game->ccolor = get_info(game, line);
}

void	map_check(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
		!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) ||
		!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		map_info(game, line);
	else if (ft_strlen(line) == 0)
		return ;
}		
		
static void	map_size(t_game *game, int fd)
{
	char	c;
	int	temp;

	temp = 0;
	while (read(fd, &c, 1) > 0)
	{	
		if (
		if (c == '\n')
		{
			game->y++;
			temp = 0;
		}
		else
			temp++;
		if(temp > game->x)
			game->x = temp - 6;
		}
	}
	close(fd);
}	

void	map_malloc(t_game *game, char *line)
{
	map_size(game, fd);
	if (game->y == 0 || game->x == 0)
		exit_error(0, "Invalid map. It's empty.", game);
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (new);
}
	
int	map_init(t_game *game, char *filename)
{
	char	*mapping;
	char	*temp;
	int	fd;
	
	fd = open(filename, O_RDONLY);
	mapping = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if (temp = NULL)
			break ;
		if (game->info == 6)
			mapping = strjoin_free(mapping, temp);
		else
		{
			map_check(game, temp);
			free(temp);
		{
	}
	game->map = ft_split(mapping, '\n');
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
	map_malloc(game, fd);
	map_init(game, filename);
}


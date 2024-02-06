/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:40:15 by sum               #+#    #+#             */
/*   Updated: 2024/01/23 13:40:18 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

int	color_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	get_rgb(char *line, int *rgb)
{
	char	**temp;
	int	color;
	int	i;
	
	if (ft_strchr(line, ',') == 0)
		temp = ft_split(line, ',');
	else
		return (1);
	i = -1;
	while (temp[++i])
	{
		if (color_valid(temp[i]))
			return (1);
		color = ft_atoi(temp[i]);
		printf("%d color \n", color);
		if (color < 0 || color > 255)
			return (1);
		rgb[i] = color;
	}
	free_split(temp);
	if (i != 2)
		return (1);
	return (0);
}
	
		
void	map_background(t_game *game, char *line, int info)
{
	char	**color;
	int	rgb[3];
	
	if (ft_strchr(line, ','))
		color = ft_split(line, ' ');
	else
		exit_error(0, "Color information is not valid.", game);
	if (!get_rgb(color[1], rgb))
		exit_error(0, "Color information is not valid.", game);
	if (info == FLOOR)
		game->floor = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else
		game->ceiling = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	game->info++;
	free_split(color);
}

	
char	*get_info(t_game *game, char *line)
{
	char	**temp;
	char	*file;
	int	fd;
	
	
	temp = ft_split(line, ' ');
	if (!temp)
		exit_error(0, "Information Error", game);
	file = ft_strtrim(temp[1], "\n");
	free_split(temp);

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(0, "Failed to open the map image.", game);
	game->info++;
	return (file);
}


void	map_info(t_game *game, char *line)
{
	if (!ft_strncmp(line, "WE ", 3))
		game->we = get_info(game, line);
	else if (!ft_strncmp(line, "NO ", 3))
		game->no = get_info(game, line);
	else if (!ft_strncmp(line, "SO ", 3))
		game->so = get_info(game, line);
	else if (!ft_strncmp(line, "EA ", 3))
		game->ea = get_info(game, line);
	else if (!ft_strncmp(line, "F ", 2))
		map_background(game, line, FLOOR);
	else if (!ft_strncmp(line, "C ", 2))
		map_background(game, line, FLOOR);
	else
		return ;
}		


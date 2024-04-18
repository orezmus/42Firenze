/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:31:27 by femorell          #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

int	color_valid(char *str, int flag)
{
	int	i;

	i = -1;
	if (flag == 0)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (1);
		}
	}
	else
	{
		while (*str++)
		{
			if (*str == ',')
				i++;
		}
		if (i == 1)
			return (1);
	}
	return (0);
}

int	get_rgb(char *line, int *rgb, int *i)
{
	char	**temp;
	int		color;
	int		j;

	temp = ft_split(line, ',');
	j = -1;
	while (temp[++j])
	{
		if (color_valid(temp[j], 0))
		{
			free_split(temp);
			return (1);
		}
		color = ft_atoi(temp[j]);
		if (color < 0 || color > 255)
		{
			free_split(temp);
			return (1);
		}
		rgb[*i] = color;
		(*i)++;
	}
	free_split(temp);
	return (0);
}

void	map_coloring(t_game *game, int *rgb, int info)
{
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		exit_error(1, "Color information is not valid.", NULL, game);
	if (info == FLOOR)
		game->floor = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else
		game->ceiling = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	game->info++;
}

void	map_background(t_game *game, char *line, int info)
{
	char	**color;
	int		i;
	int		rgb[3];
	int		count;

	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	if (color_valid(line, 1))
		color = ft_split(line, ' ');
	else
		exit_error(1, "Color information is not valid.", NULL, game);
	i = 0;
	count = 0;
	while (color[++i])
	{
		if (get_rgb(color[i], rgb, &count))
		{
			free_split(color);
			exit_error(1, "Color information is not valid.", NULL, game);
		}
	}
	free_split(color);
	map_coloring(game, rgb, info);
}

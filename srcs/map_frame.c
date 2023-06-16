/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:10:51 by sum               #+#    #+#             */
/*   Updated: 2023/03/13 15:10:52 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	frame_anim(t_game *game)
{	
	static int	num_img;
	static int	img_inter;

	if (img_inter > game->size.x * 20)
	{
		img_inter = 0;
		if (num_img < 1)
			num_img++;
		else
			num_img = 0;
	}
	else
		img_inter++;
	return (num_img);
}

char	*ft_str_add(char *str, int n, char c, t_alloc **alloc)
{
	int		i;
	char	*new;
	int		len;

	len = ft_strlen(str);
	i = 0;
	new = ft_malloc(sizeof(char) * (ft_strlen(str) + n + 1), alloc);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (i < len + n)
	{
		new[i] = c;
		i++;
	}
	new[i] = 0;
	return (new);
}

static char	**resize_y(t_game *game, char **map, t_alloc **alloc)
{
	int		i;
	char	**new;

	i = 0;
	new = ft_malloc(sizeof(char *) * (game->size.y + 3), alloc);
	if (!new)
		return (NULL);
	new[i] = ft_str_add("\0", game->size.x, 'F', alloc);
	while (i < game->size.y)
	{
		new[i + 1] = ft_strdup_alloc(map[i], *alloc);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[++i] = ft_str_add("\0", game->size.x, 'F', alloc);
	new[++i] = NULL;
	game->size.y += 2;
	return (new);
}

static char	**resize_x(t_game *game, char **map, t_alloc **alloc)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_malloc(sizeof(char *) * (game->size.x + 4), alloc);
	if (!new)
		return (NULL);
	while (map[i])
	{
		new[i] = ft_strjoin_alloc("F", map[i], alloc);
		new[i] = ft_str_add(new[i], 1, 'F', alloc);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	game->size.x += 2;
	return (new);
}

char	**map_frame(t_game *game, char **map, t_alloc **alloc)
{
	int	i;

	i = -1;
	map = resize_x(game, map, alloc);
	map = resize_y(game, map, alloc);
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	return (map);
}

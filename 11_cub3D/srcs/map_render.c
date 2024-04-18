/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:59 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	img_render(t_game *game, int *texture, char *path)
{
	t_image	img;
	int		x;
	int		y;

	img.image = mlx_xpm_file_to_image(game->mlx, path, &img.width, &img.height);
	if (!img.image)
	{
		free_game(game);
		printf("Error\nInvalid texture.\n");
		exit(1);
	}
	img.addr = (int *)mlx_get_data_addr(img.image, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			texture[img.width * y + x] = img.addr[img.width * y + x];
	}
	mlx_destroy_image(game->mlx, img.image);
}

void	map_render(t_game *game)
{
	img_render(game, game->wall[SO], game->so);
	img_render(game, game->wall[NO], game->no);
	img_render(game, game->wall[EA], game->ea);
	img_render(game, game->wall[WE], game->we);
}

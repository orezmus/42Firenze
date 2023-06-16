/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:13 by sum               #+#    #+#             */
/*   Updated: 2023/03/13 15:11:14 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	construct_image(char *buffer, t_vector pos,
	t_image image2, t_image image)
{
	int	y;
	int	x;
	int	pixel;
	int	og;

	y = 0;
	while (y <= image.height)
	{
		x = 0;
		while (x <= image.width)
		{
			pixel = ((pos.y + y) * image2.line_length) + ((pos.x + x) * 4);
			og = (y * image.line_length) + (x * 4);
			if (!(image.addr[og] == 0 && image.addr[og + 1] == 0
					&& image.addr[og + 2] == 0))
			{
				buffer[pixel + 0] = image.addr[og + 0];
				buffer[pixel + 1] = image.addr[og + 1];
				buffer[pixel + 2] = image.addr[og + 2];
				buffer[pixel + 3] = image.addr[og + 3];
			}
			x++;
		}
		y++;
	}
}

void	shadow(char *buffer, t_vector pos, t_image image2, t_image image)
{
	int	y;
	int	x;
	int	pixel;
	int	og;

	y = 0;
	while (y <= image.height)
	{
		x = 0;
		while (x <= image.width)
		{
			pixel = ((pos.y + y) * image2.line_length) + ((pos.x + x) * 4);
			og = (y * image.line_length) + (x * 4);
			if (!(image.addr[og] == 0 && image.addr[og + 1] == 0
					&& image.addr[og + 2] == 0))
			{
				buffer[pixel + 0] = ((buffer[pixel + 0] >> 1) & 0x7F7F7F);
				buffer[pixel + 1] = ((buffer[pixel + 1] >> 1) & 0x7F7F7F);
				buffer[pixel + 2] = ((buffer[pixel + 2] >> 1) & 0x7F7F7F);
				buffer[pixel + 3] = ((buffer[pixel + 3] >> 1) & 0x7F7F7F);
			}
			x++;
		}
		y++;
	}
}

t_image	generate_image(t_game game, char *path, t_alloc **alloc)
{
	t_image	sprite;

	sprite.image = mlx_xpm_file_to_image(game.mlx, path, &sprite.width,
			&sprite.height);
	if (!sprite.image)
		return (sprite);
	sprite.addr = mlx_get_data_addr(sprite.image, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	malloc_add(alloc, malloc_new(sprite.image));
	return (sprite);
}

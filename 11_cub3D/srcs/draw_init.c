/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:58 by sum               #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	get_wall(t_game *game, t_ray *ray)
{
	if (ray->raydir_x > 0 && ray->side == 0)
		ray->tex_num = EA;
	else if (ray->raydir_x < 0 && ray->side == 0)
		ray->tex_num = WE;
	else if (ray->raydir_y > 0 && ray->side == 1)
		ray->tex_num = NO;
	else
		ray->tex_num = SO;
	if (ray->side == 1)
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist * ray->raydir_x;
	else
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist * ray->raydir_y;
	ray->wall_x -= floor(ray->wall_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		color;
	double	step;

	step = 1.0 * TEX_H / ray->line_height;
	ray->tex_pos = \
		(ray->draw_start - SCREEN_H / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end && y < SCREEN_H)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_H - 1);
		ray->tex_pos += step;
		color = game->wall[ray->tex_num][TEX_H * ray->tex_y + ray->tex_x];
		if (ray->side == 0)
			color = (color >> 1) & 8355711;
		game->texture.addr[SCREEN_W * y + x] = color;
		y++;
	}
}

void	draw_color(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = -1;
	while (++y < SCREEN_H)
	{
		if (y < ray->draw_start)
			game->texture.addr[SCREEN_W * y + x] = game->ceiling;
		else if (y > ray->draw_end)
			game->texture.addr[SCREEN_W * y + x] = game->floor;
	}
}

void	draw_init(t_game *game, t_ray *ray, int x)
{
	ray->line_height = (int)(SCREEN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
	get_wall(game, ray);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_W);
	if (ray->side == 1 && ray->raydir_y > 0)
		ray->tex_x = TEX_W - ray->tex_x - 1;
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->tex_x = TEX_W - ray->tex_x - 1;
	draw_wall(game, ray, x);
	draw_color(game, ray, x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:28:12 by femorell          #+#    #+#             */
/*   Updated: 2024/03/05 19:07:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	dda_perform(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	dda_init(t_game *game, t_ray *ray)
{
	t_player	*p;

	p = game->player;
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (p->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - p->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (p->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - p->pos_y) * ray->deltadist_y;
	}
}

void	ray_init(t_game *game, t_ray *ray, int x)
{
	double		camera_x;
	t_player	*p;

	p = game->player;
	camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->raydir_x = p->dir_x + p->plane_x * camera_x;
	ray->raydir_y = p->dir_y + p->plane_y * camera_x;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;
	ray->deltadist_x = \
	sqrt(1 + (ray->raydir_y * ray->raydir_y) / (ray->raydir_x * ray->raydir_x));
	ray->deltadist_y = \
	sqrt(1 + (ray->raydir_x * ray->raydir_x) / (ray->raydir_y * ray->raydir_y));
	ray->hit = 0;
	dda_init(game, ray);
	dda_perform(game, ray);
	if (ray->side == 0)
		ray->perp_wall_dist = \
		(ray->map_x - p->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perp_wall_dist = \
		(ray->map_y - p->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
}

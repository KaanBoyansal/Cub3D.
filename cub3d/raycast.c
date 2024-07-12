/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:36:14 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:33:50 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_data *data, t_ray *ray, double angle)
{
	ray->ray_dir.x = cos(angle);
	ray->ray_dir.y = sin(angle);
	ray->map_x = (int)data->player->pos_x;
	ray->map_y = (int)data->player->pos_y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

void	calculate_step_and_dist(t_data *data, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x
			= (data->player->pos_x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - data->player->pos_x);
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y
			= (data->player->pos_y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - data->player->pos_y);
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

void	ray_step(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = EAST_WEST;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = NORTH_SOUTH;
	}
}

int	is_boundary_violated(t_ray *ray, int map_size)
{
	if (ray->map_x < 0 || ray->map_y < 0)
		return (1);
	if (ray->map_x >= map_size || ray->map_y >= map_size)
		return (1);
	return (0);
}

void	determine_texture(t_data *data, t_ray *ray)
{
	if (ray->side == EAST_WEST)
	{
		if (ray->ray_dir.x > 0)
			ray->texture = (&data->imgs[3]);
		else
			ray->texture = (&data->imgs[0]);
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->texture = (&data->imgs[1]);
		else
			ray->texture = (&data->imgs[2]);
	}
}

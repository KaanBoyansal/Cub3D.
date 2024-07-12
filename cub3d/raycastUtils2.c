/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastUtils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:34:32 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:35:02 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_floor_ceiling(t_data *data, int x, int lineHeight)
{
	int	start;
	int	end;
	int	y;

	start = (WINDOW_HEIGHT - lineHeight) / 2;
	end = (WINDOW_HEIGHT + lineHeight) / 2;
	if (start < 0)
		start = 0;
	if (end > WINDOW_HEIGHT)
		end = WINDOW_HEIGHT;
	y = -1;
	while (++y < start)
		my_mlx_pixel_put(data->img_data, x, y, data->ceiling_color);
	y = end - 1;
	while (++y < WINDOW_HEIGHT)
		my_mlx_pixel_put(data->img_data, x, y, data->floor_color);
}

void	draw_textured_line(t_data *data, t_ray *ray, int x, int line_height)
{
	int				line_start;
	int				line_end;
	unsigned int	pixel_color;
	int				y;
	int				tex_y;

	line_start = (WINDOW_HEIGHT - line_height) / 2;
	line_end = (WINDOW_HEIGHT + line_height) / 2;
	if (line_start < 0)
		line_start = 0;
	if (line_end > WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT;
	y = line_start;
	while (++y < line_end)
	{
		tex_y = get_tex_y(y, ray, line_height);
		pixel_color = get_pixel_color(tex_y, ray);
		my_mlx_pixel_put(data->img_data, x, y, pixel_color);
	}
}

int	is_hit(t_ray *ray, t_data *data)
{
	if (is_boundary_violated(ray, WIDTH))
		return (1);
	if (data->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	calculate_perpetual(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		ray_step(ray);
		if (is_hit(ray, data))
			ray->hit = 1;
	}
	if (ray->side == EAST_WEST)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

int	safe_divide(int numerator, double denominator)
{
	if (denominator < 1e-5)
		denominator = 0.001;
	return ((int)(numerator / denominator));
}

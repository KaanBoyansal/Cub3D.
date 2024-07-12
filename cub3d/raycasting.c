/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:15 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:35:26 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycast(t_data *data)
{
	double	angle;
	int		line_height;
	t_ray	ray;
	int		x;

	angle = data->player->dir_radian - FOV / 2;
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_ray(data, &ray, angle);
		calculate_step_and_dist(data, &ray);
		calculate_perpetual(data, &ray);
		determine_texture(data, &ray);
		calculate_texture_x(data, &ray);
		ray.perp_wall_dist *= cos(data->player->dir_radian - angle);
		line_height = safe_divide(WINDOW_HEIGHT, ray.perp_wall_dist);
		draw_textured_line(data, &ray, x, line_height);
		draw_floor_ceiling(data, x, line_height);
		angle += ANGLE_STEP;
	}
}

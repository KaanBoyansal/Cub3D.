/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:32:26 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:34:13 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fix_mirror(t_ray *ray)
{
	if ((ray->side == 0 && ray->ray_dir.x < 0)
		|| (ray->side == 1 && ray->ray_dir.y > 0))
		ray->tex_x = 64 - ray->tex_x - 1;
}

void	calculate_texture_x(t_data *data, t_ray *ray)
{
	double	wallx;

	if (ray->side == EAST_WEST)
		wallx = data->player->pos_y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wallx = data->player->pos_x + ray->perp_wall_dist * ray->ray_dir.x;
	wallx -= floor((wallx));
	ray->tex_x = (int)(wallx * (double)(64));
	fix_mirror(ray);
}

unsigned int	get_pixel_color(int tex_y, t_ray *ray)
{
	unsigned int	pixel_color;
	int				texture_byte_size;
	int				texture_offset;

	texture_byte_size = ray->texture->bpp / 8;
	texture_offset = (tex_y * ray->texture->line_length);
	texture_offset += ray->tex_x * texture_byte_size;
	pixel_color = *(unsigned int *)(ray->texture->addr + texture_offset);
	return (pixel_color);
}

int	get_tex_y(int y, t_ray *ray, int line_height)
{
	double	tmp;
	double	half_screen_height;
	double	half_line_height;
	double	texture_height;
	int		tex_y;

	(void)ray;
	half_screen_height = WINDOW_HEIGHT / 2.0;
	half_line_height = line_height / 2.0;
	texture_height = (double)(64);
	tmp = (y - half_screen_height + half_line_height);
	tmp *= texture_height / line_height;
	tex_y = (int)tmp;
	return (tex_y);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	offset = (y * data->line_length + x * (data->bpp / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

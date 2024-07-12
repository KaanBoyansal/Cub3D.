/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:53:47 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:54:31 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_image(t_data *data)
{
	data->img_data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_data->addr = mlx_get_data_addr(data->img_data->img,
			&data->img_data->bpp,
			&data->img_data->line_length, &data->img_data->endian);
	data->imgs[0].img = data->ea_img;
	data->imgs[1].img = data->no_img;
	data->imgs[2].img = data->so_img;
	data->imgs[3].img = data->we_img;
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img, \
		&data->imgs[0].bpp, &data->imgs[0].line_length, &data->imgs[0].endian);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img, \
		&data->imgs[1].bpp, &data->imgs[1].line_length, &data->imgs[1].endian);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img, \
		&data->imgs[2].bpp, &data->imgs[2].line_length, &data->imgs[2].endian);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img, \
		&data->imgs[3].bpp, &data->imgs[3].line_length, &data->imgs[3].endian);
}

void	set_dir(t_player *player)
{
	if (player->dir == 'N')
		player->dir_radian = 1.5 * M_PI;
	else if (player->dir == 'S')
		player->dir_radian = 0.5 * M_PI;
	else if (player->dir == 'E')
		player->dir_radian = 0;
	else if (player->dir == 'W')
		player->dir_radian = M_PI;
}

void	init_player(t_data *data)
{
	data->player->pos_x += 0.5;
	data->player->pos_y += 0.5;
	data->player->dir_y = 0;
	data->player->dir_radian = M_PI / 4;
	set_dir(data->player);
}

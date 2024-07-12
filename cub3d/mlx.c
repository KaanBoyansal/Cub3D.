/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:57:48 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 17:48:17 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	take_imgs(t_data *data)
{
	int		i;
	char	**tmp;
	char	*line;
	int		size;

	i = -1;
	size = BLOCK_SIZE;
	while (data->fd_map[++i])
	{
		tmp = ft_split(data->fd_map[i], ' ');
		line = NULL;
		take_img_next(data, tmp, line, size);
	}
	if (!data->no_img || !data->so_img || !data->ea_img || !data->we_img)
		return (berror(4));
	return (1);
}

void	player_vals(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'W'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'E')
			{
				data->player->pos_x = x;
				data->player->pos_y = y;
				data->player->dir = data->map[y][x];
			}
		}
	}
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	if (!take_imgs(data))
		return (0);
	w_rgb_to_map(data);
	wall_image(data);
	player_vals(data);
	data->key = -1;
	init_player(data);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	init_hooks(data);
	mlx_loop(data->mlx);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxGame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:03:26 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:53:20 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_collide(double new_x, double new_y, char **map)
{
	if (map[(int)(new_y)][(int)(new_x)] == '1'
		|| map[(int)(new_y)][(int)(new_x)] == ' '
		|| map[(int)(new_y)][(int)(new_x)] == '\0')
	{
		return (1);
	}
	return (0);
}

void	ft_move2(t_player *player, int dir, t_data *data)
{
	if (dir == 'E')
	{
		player->pos_x -= player->dir_y * (MOVE_SPEED);
		player->pos_y += player->dir_x * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, data->map))
		{
			player->pos_x += player->dir_y * (MOVE_SPEED);
			player->pos_y -= player->dir_x * (MOVE_SPEED);
		}
	}
	else if (dir == 'W')
	{
		player->pos_x += player->dir_y * (MOVE_SPEED);
		player->pos_y -= player->dir_x * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, data->map))
		{
			player->pos_x -= player->dir_y * (MOVE_SPEED);
			player->pos_y += player->dir_x * (MOVE_SPEED);
		}
	}
}

void	ft_turn(t_player *player, char dir)
{
	if (dir == LEFT_ARROW)
	{
		player->dir_radian -= ROT_SPEED;
		if (player->dir_radian < 0)
			player->dir_radian += 2 * M_PI;
	}
	if (dir == RIGHT_ARROW)
	{
		player->dir_radian += ROT_SPEED;
		if (player->dir_radian > 2 * M_PI)
			player->dir_radian -= 2 * M_PI;
	}
}

void	ft_move(t_player *player, int dir, t_data *data)
{
	if (dir == 'N')
	{
		player->pos_x += player->dir_x * (MOVE_SPEED);
		player->pos_y += player->dir_y * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, data->map))
		{
			player->pos_x -= player->dir_x * (MOVE_SPEED);
			player->pos_y -= player->dir_y * (MOVE_SPEED);
		}
	}
	else if (dir == 'S')
	{
		player->pos_x -= player->dir_x * (MOVE_SPEED);
		player->pos_y -= player->dir_y * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, data->map))
		{
			player->pos_x += player->dir_x * (MOVE_SPEED);
			player->pos_y += player->dir_y * (MOVE_SPEED);
		}
	}
	else if (dir == 'E' || dir == 'W')
		ft_move2(player, dir, data);
}

void	routine(t_data *data)
{
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_data->img, 0, 0);
}

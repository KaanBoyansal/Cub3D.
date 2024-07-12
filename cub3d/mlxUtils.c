/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:51:15 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:51:35 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window(void)
{
	exit_free();
	return (0);
}

int	ft_press(int key, t_data *data)
{
	data->key = key;
	if (key == ESC)
		close_window();
	return (0);
}

int	ft_release(int key, t_data *data)
{
	if (key == data->key)
		data->key = -1;
	return (0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, close_window, NULL);
	mlx_hook(data->mlx_win, 2, 0, ft_press, data);
	mlx_hook(data->mlx_win, 3, 0, ft_release, data);
	mlx_loop_hook(data->mlx, render, data);
}

int	render(t_data *data)
{
	data->player->dir_x = cos(data->player->dir_radian);
	data->player->dir_y = sin(data->player->dir_radian);
	if (data->key == W)
		ft_move(data->player, 'N', data);
	else if (data->key == S)
		ft_move(data->player, 'S', data);
	else if (data->key == A)
		ft_move(data->player, 'W', data);
	else if (data->key == D)
		ft_move(data->player, 'E', data);
	else if (data->key == LEFT_ARROW)
		ft_turn((data->player), LEFT_ARROW);
	else if (data->key == RIGHT_ARROW)
		ft_turn((data->player), RIGHT_ARROW);
	routine(data);
	return (0);
}

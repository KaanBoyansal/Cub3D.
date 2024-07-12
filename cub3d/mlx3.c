/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:07:26 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 17:48:49 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	updown_next(t_data *data, int i, int j)
{
	if (i && (data->map[i][j] == 'W' || data->map[i][j] == 'E'
		|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
		&& ft_str_len(data->map[i - 1]) < j)
		return (0);
	else if (i && (data->map[i][j] == 'W' || data->map[i][j] == 'E'
		|| data->map[i][j] == 'N'
			|| data->map[i][j] == 'S') && data->map[i - 1][j] == ' ')
		return (0);
	if (i && (data->map[i][j] == 'W' || data->map[i][j] == 'E'
		|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
		&& ft_str_len(data->map[i + 1]) < j)
		return (0);
	else if (i && (data->map[i][j] == 'W' || data->map[i][j] == 'E'
		|| data->map[i][j] == 'N'
			|| data->map[i][j] == 'S') && data->map[i + 1][j] == ' ')
		return (0);
	return (1);
}

int	linebyline_next(t_data *data, int i, int j)
{
	if (!j && data->map[i][j] == '0'
		&& (data->map[i][j + 1] == ' '
		|| data->map[i][j + 1] == '\n'
		|| data->map[i][j + 1] == 0))
		return (0);
	else if (data->map[i][j] == '0'
		&& (data->map[i][j + 1] == ' '
			|| data->map[i][j - 1] == ' '
			|| data->map[i][j + 1] == 0
			|| data->map[i][j + 1] == '\n'))
		return (0);
	return (1);
}

void	take_img_next(t_data *data, char **tmp, char *line, int size)
{
	if (tmp[1])
		line = ft_strtrim(tmp[1], "\n");
	if (!ft_strcmp(tmp[0], "NO"))
		data->no_img = mlx_xpm_file_to_image(data->mlx, line, &size, &size);
	else if (!ft_strcmp(tmp[0], "SO"))
		data->so_img = mlx_xpm_file_to_image(data->mlx, line, &size, &size);
	else if (!ft_strcmp(tmp[0], "EA"))
		data->ea_img = mlx_xpm_file_to_image(data->mlx, line, &size, &size);
	else if (!ft_strcmp(tmp[0], "WE"))
		data->we_img = mlx_xpm_file_to_image(data->mlx, line, &size, &size);
	if (tmp)
		free_arr(tmp);
	if (line != NULL)
		free(line);
}

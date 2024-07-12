/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:55:57 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 16:32:45 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ch_check(t_data *data, int start)
{
	int	i;

	start++;
	while (data->fd_map[start])
	{
		i = -1;
		while (data->fd_map[start][++i])
		{
			if (data->fd_map[start][i] != ' ' && data->fd_map[start][i] != '1'
				&& data->fd_map[start][i] != '0'
				&& data->fd_map[start][i] != 'N'
				&& data->fd_map[start][i] != 'W'
				&& data->fd_map[start][i] != 'E'
				&& data->fd_map[start][i] != 'S'
				&& data->fd_map[start][i] != '\n')
				return (0);
		}
		start++;
	}
	return (1);
}

int	check_map(t_data *data)
{
	cpy_map(data);
	if (!data->fd_map || !data->fd_map[0]
		|| !data->fd_map[0][0])
		return (berror(9));
	if (len_pt(data->fd_map) < 9)
		return (berror(9));
	if (!check_lines(data))
		return (0);
	if (!rgb_check(data))
		return (0);
	cpy_gamemap(data);
	if (!is_valid(data))
		return (0);
	if (!is_valid_dir(data))
		return (0);
	if (!another_map(data))
		return (0);
	return (1);
}

void	cpy_map(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->fd_map = ft_calloc(sizeof(char *), 1000);
	line = get_next_line(data->fd);
	while (line)
	{
		data->fd_map[i] = line;
		line = get_next_line(data->fd);
		i++;
	}
	data->fd_map[i] = NULL;
}

void	free_line_tmp(char *line, char **tmp)
{
	if (line)
		free(line);
	if (tmp)
		free_arr(tmp);
}

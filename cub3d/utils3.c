/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:24:07 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:52:47 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	w_rgb_to_map(t_data *data)
{
	data->floor_color = (data->f[0] << 16) + (data->f[1] << 8) + data->f[2];
	data->ceiling_color = (data->c[0] << 16) + (data->c[1] << 8) + data->c[2];
}

int	another_map(t_data *data)
{
	int		i;
	int		flag;
	int		j;
	char	*line;

	i = -1;
	flag = 0;
	while (data->map[++i])
	{
		j = -1;
		line = ft_strtrim(data->map[i], " ");
		if ((line[0] == '\n' || !line[0]) && !flag)
			flag = 1;
		if (flag && (line[0] != '\n' || !line[0]))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	index_check(char **vals)
{
	int		i;
	char	**tmp;

	i = -1;
	while (vals[++i])
	{
		tmp = ft_split(vals[i], ' ');
		if (tmp[1] != NULL)
		{
			free_arr(tmp);
			return (berror(6));
		}
		free_arr(tmp);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:38:13 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 19:07:55 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	updown_if(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' && (!data->map[i + 1]
		|| data->map[i + 1][0] == '\n'))
		return (0);
	if (i && data->map[i][j] == '0'
		&& ft_str_len(data->map[i - 1]) < j)
		return (0);
	else if (i && data->map[i][j] == '0' &&
		(data->map[i - 1][j] == ' ' || data->map[i - 1][j] == '\n'))
		return (0);
	if (i && data->map[i][j] == '0'
		&& ft_str_len(data->map[i + 1]) < j)
		return (0);
	else if (i && data->map[i][j] == '0' &&
		(data->map[i + 1][j] == ' ' || data->map[i + 1][j] == '\n'))
		return (0);
	return (1);
}

int	linebyline_check_dir(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!j && (data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
				&& (data->map[i][j + 1] == ' '
					|| data->map[i][j + 1] == '\n'
					|| data->map[i][j + 1] == 0))
				return (0);
			else if ((data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
				&& (data->map[i][j + 1] == ' '
					|| data->map[i][j - 1] == ' '
					|| data->map[i][j + 1] == 0
					|| data->map[i][j + 1] == '\n'))
				return (0);
		}
	}
	return (1);
}

int	updown_check_dir(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!updown_next(data, i, j))
				return (0);
		}
	}
	return (1);
}

int	count_dirs(t_data *data)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	counter = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'N')
				counter++;
		}
	}
	if (counter != 1)
		return (0);
	return (1);
}

int	is_valid_dir(t_data *data)
{
	if (!count_dirs(data))
		return (0);
	if (!linebyline_check_dir(data))
		return (0);
	if (!updown_check_dir(data))
		return (0);
	return (1);
}

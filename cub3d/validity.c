/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:38:11 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 19:24:37 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	count_dot(char *file)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (file[++i])
	{
		if (file[i] == '.')
			count++;
	}
	if (!count || count > 2)
		return (0);
	return (1);
}

int	check_file(char *file)
{
	int		i;

	i = ft_str_len(file);
	if (!count_dot(file))
		return (0);
	if (i > 4 && file[i - 1] == 'b' && file[i - 2] == 'u'
		&& file[i - 3] == 'c' && file[i - 4] == '.'
		&& ((file[i - 5] >= 'A' && file[i - 5] <= 'Z')
			|| (file[i - 5] >= 'a' && file[i - 5] <= 'z')
			|| (file[i - 5] >= '0' && file[i - 5] <= '9')))
	{
		return (1);
	}
	return (0);
}

int	linebyline_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!i && data->map[i][j] != '1' && data->map[i][j] != ' '
				&& data->map[i][j] != '\n')
				return (0);
			if (!linebyline_next(data, i, j))
				return (0);
		}
	}
	return (1);
}

int	updown_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!updown_if(data, i, j))
				return (0);
		}
	}
	return (1);
}

int	is_valid(t_data *data)
{
	if (!linebyline_check(data))
		return (0);
	if (!updown_check(data))
		return (0);
	return (1);
}

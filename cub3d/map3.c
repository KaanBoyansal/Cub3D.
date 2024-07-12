/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:09:18 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 14:17:35 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_next_c(t_data *data, char *line, char **values, char *tmp)
{
	if (values[0][0] == 'C')
	{
		data->rgb_c++;
		if (data->rgb_c > 1)
		{
			free(line);
			free_arr(values);
			return (0);
		}
		data->rgb_flag = 'C';
		tmp = values[0];
		values[0] = ft_strtrim(values[0], "C");
		free(tmp);
	}
	return (1);
}

int	rgb_next(t_data *data, char *line, char **values, char *tmp)
{
	if (values[0][0] == 'F')
	{
		data->rgb_f++;
		if (data->rgb_f > 1)
		{
			free(line);
			free_arr(values);
			return (0);
		}
		data->rgb_flag = 'F';
		tmp = values[0];
		values[0] = ft_strtrim(values[0], "F");
		free(tmp);
	}
	else if (!rgb_next_c(data, line, values, tmp))
		return (0);
	if (!check_values(values, data))
	{
		free(line);
		free_arr(values);
		return (0);
	}
	return (1);
}

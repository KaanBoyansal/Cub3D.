/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:09:40 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 14:22:21 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_check(t_data *data)
{
	int		i;
	char	**values;
	char	*line;
	char	*tmp;

	i = -1;
	data->rgb_c = 0;
	data->rgb_f = 0;
	while (data->fd_map[++i])
	{
		data->rgb_flag = 0;
		values = NULL;
		tmp = NULL;
		line = ft_strtrim(data->fd_map[i], " ");
		if (!ft_strncmp(line, "F", 1)
			|| !ft_strncmp(line, "C", 1))
		{
			values = ft_split(line, ',');
			if (!rgb_next(data, line, values, tmp))
				return (0);
			free_arr(values);
		}
		free(line);
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != 0 && n-- > 1)
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	minus = 0;
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (minus)
		return (-res);
	return (res);
}

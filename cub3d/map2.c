/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:51:47 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/28 14:28:37 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_in_arrray(char s1, char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (s1 == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strrtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		k;
	int		j;
	char	*arr;

	i = 0;
	k = 0;
	len = ft_strlen((char *)s1);
	while (is_in_arrray(s1[i], (char *)set) && s1[i])
		i++;
	j = len - 1;
	while (j > i && is_in_arrray(s1[j], (char *)set))
		j--;
	arr = ft_substr(s1, i, j - i + 1);
	if (!arr)
		return (0);
	return (arr);
}

void	cpy_gamemap(t_data *data)
{
	int		i;
	char	*line;

	i = -1;
	while (data->fd_map[++i])
	{
		line = ft_strtrim(data->fd_map[i], " ");
		if (line[0] == '1' || line[0] == '0')
		{
			if (line)
				free(line);
			break ;
		}
		if (line)
			free(line);
	}
	game_map(data, i);
}

void	game_map(t_data *data, int start)
{
	int	size;
	int	st;

	st = start;
	size = 0;
	while (data->fd_map[st++])
		size++;
	data->map = malloc(sizeof(char *) * (size + 1));
	size = 0;
	while (data->fd_map[start])
	{
		data->map[size] = ft_strdup(data->fd_map[start]);
		size++;
		start++;
	}
	data->map[size] = NULL;
}

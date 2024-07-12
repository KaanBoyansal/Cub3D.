/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 04:10:49 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 17:34:05 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int a, char **args)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->img_data = ft_calloc(sizeof(t_img), 1);
	data->player = ft_calloc(sizeof(t_player), 1);
	if (a == 2)
	{
		data->fd = open(args[1], O_RDONLY);
		if (data->fd == -1)
			return (berror(5));
		else if (!check_file(args[1]))
			return (berror(1));
		else if (!check_map(data))
			return (berror(2));
		if (!init_mlx(data))
			return (berror(3));
	}
	else
		printf("Error\nInvalid params(Give only file name as parameter)!\n");
	return (0);
}

int	count_comma(char **line)
{
	int	i;
	int	j;
	int	ct;

	i = -1;
	ct = 0;
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
			if (line[i][j] == ',')
				ct++;
	}
	if (ct > 2)
		return (berror(6));
	return (1);
}

int	single_line_check(char **line, t_data *data)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (1);
	if (!count_comma(line))
		return (0);
	while (line[i])
		i++;
	if ((!ft_strcmp(line[0], "F")
			|| !ft_strcmp(line[0], "C")) && !(i >= 2 && i <= 6))
		return (0);
	if ((ft_strcmp(line[0], "F")
			&& ft_strcmp(line[0], "C")) && i != 2)
		return (0);
	i = -1;
	if (!loop(i, line))
		return (0);
	data->count++;
	return (1);
}

int	check_lines(t_data *data)
{
	int		i;
	char	*line;
	char	**tmp;

	i = -1;
	data->count = 0;
	while (data->fd_map[++i])
	{
		line = ft_strdup(data->fd_map[i]);
		tmp = NULL;
		if (line && line[0] && line[0] != '\n')
			tmp = ft_split(line, ' ');
		if (!if_func(tmp, data, line))
			return (0);
		if (data->count == 6)
		{
			free_line_tmp(line, tmp);
			break ;
		}
		free_line_tmp(line, tmp);
	}
	return (ch_check(data, i));
}

int	len_pt(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

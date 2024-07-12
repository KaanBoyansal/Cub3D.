/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:01:29 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 15:22:56 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	loop(int i, char **line)
{
	while (line[++i])
	{
		if (i == 0)
		{
			if (ft_strcmp(line[i], "NO") && ft_strcmp(line[i], "SO")
				&& ft_strcmp(line[i], "C") && ft_strcmp(line[i], "F")
				&& ft_strcmp(line[i], "EA") && ft_strcmp(line[i], "WE"))
				return (0);
		}
	}
	return (1);
}

int	if_func(char **tmp, t_data *data, char *line)
{
	if (!single_line_check(tmp, data) && data->count != 6)
	{
		if (line)
			free(line);
		if (tmp)
			free_arr(tmp);
		return (0);
	}
	return (1);
}

void	exit_free(void)
{
	exit(0);
}

int	berror(int ernum)
{
	if (ernum == 1)
		printf("Error\nInvalid file type\n");
	else if (ernum == 2)
		printf("Error\nInvalid map! Please check your map file!\n");
	else if (ernum == 3)
		printf("Error\nGame does not start\n");
	else if (ernum == 4)
		printf("Error\nFailed to load images\n");
	else if (ernum == 5)
		printf("Error\nCheck your map's path!\n");
	else if (ernum == 6)
		printf("Error\nWrong aligned commas!\n");
	else if (ernum == 7)
		printf("Error\nDuplicate texture paths!\n");
	else if (ernum == 9)
		printf("Error\nMap file is empty!\n");
	if (ernum == 7 || ernum == 4 || ernum == 6)
		ernum = 0;
	exit_free();
	return (ernum);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:37:33 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 13:52:40 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if ((int)len - (int)start > ft_str_len((char *)s) && (start == 0
			|| (int)len > ft_str_len((char *)s)))
		ptr = malloc(ft_str_len((char *)s));
	else
		ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
			ptr[j++] = s[i];
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int	vals_valid(char **vals)
{
	int	i;
	int	j;

	i = -1;
	while (vals[++i])
	{
		j = -1;
		while (vals[i][++j])
		{
			if (vals[i][j] != ',' && vals[i][j] != ' '
				&& !(vals[i][j] >= '0' && vals[i][j] <= '9')
					&& vals[i][j] != '\n')
				return (0);
			if (vals[i][j] == '0'
				&& !(vals[i][j - 1] >= '0' && vals[i][j - 1] <= '9')
				&& (vals[i][j + 1] >= '0' && vals[i][j + 1] <= '9'))
				return (0);
		}
	}
	return (1);
}

int	check_values(char **vals, t_data *data)
{
	int	tmp;
	int	i;

	i = -1;
	if (!vals_valid(vals))
		return (0);
	if (!index_check(vals))
		return (0);
	if (data->rgb_flag == 'C')
		data->c = malloc(sizeof(int) * 3);
	else if (data->rgb_flag == 'F')
		data->f = malloc(sizeof(int) * 3);
	while (vals[++i])
	{
		tmp = ft_atoi(vals[i]);
		if (!(tmp >= 0 && tmp <= 255))
			return (0);
		if (data->rgb_flag == 'C')
			data->c[i] = tmp;
		else if (data->rgb_flag == 'F')
			data->f[i] = tmp;
	}
	return (1);
}

int	is_in_array(char s1, char *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		k;
	int		j;
	char	*arr;

	i = 0;
	k = 0;
	len = ft_str_len((char *)s1);
	while (is_in_array(s1[i], (char *)set) && s1[i])
		i++;
	j = len - 1;
	while (j > i && is_in_array(s1[j], (char *)set))
		j--;
	arr = ft_substr(s1, i, j - i + 1);
	if (!arr)
		return (0);
	return (arr);
}

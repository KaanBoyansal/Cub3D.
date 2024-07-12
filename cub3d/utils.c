/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 04:13:10 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/11 10:19:24 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	char			*c;

	i = 0;
	c = s;
	while (i < n)
		c[i++] = 0;
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	p = malloc(nelem * elsize);
	if (!p)
		return (0);
	ft_bzero(p, nelem * elsize);
	return (p);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	p = str;
	while (*s)
	{
		*p = *s;
		p++;
		s++;
	}
	*p = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:06:32 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/20 19:24:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char const *str, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	if (!(str[0] == c) && str[0])
		cnt++;
	while (str[++i])
	{
		if ((!str[i] || str[i] == c) && !(str[i + 1] == c) && str[i + 1])
			cnt++;
	}
	return (cnt);
}

static void	sp_strcpy(char *target, char const *arrow, int *i, char c)
{
	int	index;

	index = 0;
	while (arrow[*i] == c || !arrow[*i])
		(*i)++;
	while (!(arrow[*i] == c) && arrow[*i])
	{
		target[index] = arrow[*i];
		(*i)++;
		index++;
	}
	target[index] = 0;
}

static int	strsize(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] == c || !s[i])
		i++;
	while (!(s[i + size] == c) && s[i + size])
		size++;
	return (size + 1);
}

static int	mkstr(char **result, int index, int size)
{
	int	i;

	i = 0;
	result[index] = (char *)malloc(sizeof(char) * size);
	if (!result[index])
	{
		while (i < index)
		{
			free (result[i]);
			i++;
		}
		free (result);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		strcnt;
	int		i;
	int		j;
	int		size;

	j = 0;
	i = 0;
	strcnt = strcount(s, c);
	result = (char **)malloc(sizeof(char *) * (strcnt + 1));
	if (!result)
		return (0);
	while (i < strcnt)
	{
		size = strsize(s, c, j);
		if (!(mkstr(result, i, size)))
			return (0);
		sp_strcpy(result[i], s, &j, c);
		i++;
	}
	result[strcnt] = 0;
	return (result);
}

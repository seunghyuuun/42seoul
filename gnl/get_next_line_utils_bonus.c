/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:46:52 by seunghy2          #+#    #+#             */
/*   Updated: 2023/05/29 19:46:54 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*allfree(char *a, char *b, char *result)
{
	if (a)
		free (a);
	if (b)
		free (b);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*result;
	size_t	j;

	i = -1;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	tofind;
	char	*temp;

	if (!s)
		return (0);
	tofind = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == tofind)
			return (temp);
		temp++;
	}
	if (!tofind)
		return (temp);
	return (0);
}

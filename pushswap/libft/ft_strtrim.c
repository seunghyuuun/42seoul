/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:47:53 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:27 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	setcheck(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*result;
	int		len;
	int		i;

	start = (char *)s1;
	while (setcheck(set, *start))
		start++;
	i = -1;
	len = -1;
	while (start[++i])
	{
		if (!(setcheck(set, start[i])))
			len = i;
	}
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (0);
	i = -1;
	while (++i < len + 1)
		result[i] = start[i];
	result[i] = 0;
	return (result);
}

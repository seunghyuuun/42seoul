/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:27:16 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/26 16:50:44 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

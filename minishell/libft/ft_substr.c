/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:59:46 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/17 13:22:37 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	temp;
	char	*result;
	size_t	i;

	size = 0;
	temp = (size_t)start;
	while (temp < ft_strlen(s) && s[temp] && size < len)
	{
		temp++;
		size++;
	}
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	i = -1;
	temp = (size_t)start;
	while (++i < size)
		result[i] = s[temp + i];
	result[i] = 0;
	return (result);
}

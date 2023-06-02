/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:13:54 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/16 15:38:04 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (needle[j] != 0 && haystack[i] == needle[j] && i < len)
			{
				i++;
				j++;
			}
			i = i - j;
			if (needle[j] == 0)
				return (&((char *)haystack)[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}

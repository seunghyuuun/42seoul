/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:08:12 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/16 12:25:23 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	i = 0;
	j = 0;
	while (dst[j] != 0)
		j++;
	dstlen = j;
	while (src[i] != 0 && j + 1 < dstsize)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	while (src[i])
	{
		j++;
		i++;
	}
	if (dstlen > dstsize)
		return (i + dstsize);
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:00:17 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/24 12:39:06 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*idst;
	unsigned char	*isrc;
	size_t			i;

	if (dst == src || !len)
		return (dst);
	idst = (unsigned char *)dst;
	isrc = (unsigned char *)src;
	if (isrc + len > idst && idst > isrc)
	{
		while (--len)
			idst[len] = isrc[len];
		idst[len] = isrc[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			idst[i] = isrc[i];
	}
	return (dst);
}

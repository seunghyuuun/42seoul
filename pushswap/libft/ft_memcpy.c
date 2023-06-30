/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:18:06 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/24 12:39:19 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*source;

	if (dst == src || !n)
		return (dst);
	temp = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n)
	{
		*temp = *source;
		temp++;
		source++;
		n--;
	}
	return (dst);
}

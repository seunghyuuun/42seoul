/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:30:20 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/07 20:30:27 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

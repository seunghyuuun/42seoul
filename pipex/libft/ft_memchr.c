/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:32:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/21 16:44:30 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	tofind;
	size_t			i;

	i = 0;
	tofind = (unsigned char)c;
	temp = (unsigned char *)s;
	while (i < n)
	{
		if (*temp == tofind)
			return ((void *)temp);
		i++;
		temp++;
	}
	return (0);
}

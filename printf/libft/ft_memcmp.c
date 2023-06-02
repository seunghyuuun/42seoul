/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:53:47 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/16 15:05:40 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	int				cmp;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (n)
	{
		cmp = *temp1 - *temp2;
		if (cmp)
			return (cmp);
		temp1++;
		temp2++;
		n--;
	}
	return (0);
}

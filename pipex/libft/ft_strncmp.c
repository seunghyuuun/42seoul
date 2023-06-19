/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:30:28 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/16 12:53:00 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		c = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (c)
			return (c);
		i++;
	}
	return (0);
}

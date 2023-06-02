/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:03:57 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/24 11:50:21 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		space;
	void		*result;

	space = count * size;
	result = malloc(space);
	if (!result)
		return (0);
	ft_bzero(result, space);
	return (result);
}

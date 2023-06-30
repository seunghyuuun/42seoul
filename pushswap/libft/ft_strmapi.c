/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:19 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/17 13:54:41 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*result;

	size = (unsigned int)ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size] = 0;
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

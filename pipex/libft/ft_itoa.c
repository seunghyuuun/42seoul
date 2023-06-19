/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:59 by seunghy2          #+#    #+#             */
/*   Updated: 2023/03/17 13:12:57 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizecheck(int n)
{
	int	result;

	if (n > 0)
		result = 0;
	else
		result = 1;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void	numtochar(char *result, int size, int n)
{
	if (n == -2147483648)
	{
		n = -214748364;
		size--;
		result[size] = '8';
	}
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n)
	{
		result[--size] = '0' + (n % 10);
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = sizecheck(n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size] = 0;
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	numtochar(result, size, n);
	return (result);
}

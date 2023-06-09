/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:46:39 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 13:49:13 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	onebyte(const char **str, int *result)
{
	int	print;

	while (**str && **str != '%')
	{
		print = write(1, *str, 1);
		if (print == -1)
		{
			*result = -1;
			return (0);
		}
		*result += print;
		(*str)++;
	}
	if (!(**str))
		return (0);
	return (1);
}

int	imax(int a, int *charnul)
{
	if (*charnul)
	{
		*charnul = 0;
		return (a + 1);
	}
	return (a);
}

void	initializer(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		result;
	int		print;
	char	*change;
	int		charnul;

	va_start(arg, str);
	initializer(&result, &charnul);
	while (1)
	{
		if (!(onebyte(&str, &result)))
		{
			va_end(arg);
			return (result);
		}
		change = argchanger(arg, &str, &charnul);
		print = write(1, change, ft_strlen(change));
		if (print == -1)
		{
			va_end(arg);
			return (-1);
		}
		free(change);
		result += imax(print, &charnul);
	}
}

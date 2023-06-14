/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:46:39 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/14 18:04:49 by seunghy2         ###   ########.fr       */
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

int	imax(size_t a, int *charnul)
{
	int	result;

	if (*charnul)
	{
		result = *charnul;
		*charnul = 0;
		return (result);
	}
	result = (int)a;
	return (result);
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
		print = write(1, change, imax(ft_strlen(change), &charnul));
		if (print == -1)
		{
			va_end(arg);
			return (-1);
		}
		free(change);
		result += print;
	}
}

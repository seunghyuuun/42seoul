/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argchanger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:06:31 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 13:08:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*optiondup(const char *str, char *type)
{
	char	*result;
	int		size;
	int		i;

	size = 1;
	while (str[size] && ft_isflag(str[size]))
		size++;
	if (str[size])
		*type = str[size++];
	result = (char *)malloc(sizeof(char) * (size));
	if (!result)
		return (0);
	i = 0;
	while (i + 1 < size)
	{
		result[i] = str[i + 1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*argchanger(va_list arg, const char **str, int *charnul)
{
	char	*change;
	char	*unchange;
	char	type;

	type = 0;
	unchange = optiondup(*str, &type);
	if (!unchange)
		return (0);
	*str += ft_strlen(unchange) + 1;
	if (type == 'c')
		change = ch_char(unchange, va_arg(arg, int), charnul, 1);
	else if (type == 's')
		change = ch_str(unchange, va_arg(arg, char *));
	else if (type == 'p')
		change = ch_pnt(unchange, va_arg(arg, void *));
	else if (type == 'x' || type == 'X')
		change = ch_hexa(unchange, va_arg(arg, unsigned int), type);
	else if (type == 'u')
		change = ch_unsign(unchange, va_arg(arg, unsigned int));
	else if (type == 'd' || type == 'i')
		change = ch_int(unchange, va_arg(arg, int));
	else
		change = ch_char(unchange, type, charnul, 0);
	free(unchange);
	return (change);
}

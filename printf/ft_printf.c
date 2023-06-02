/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:46:39 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/02 19:42:37 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		result;

	va_start(arg, str);

	result = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i] == '%')
			diff += changer(&str[i], arg);
	}
}

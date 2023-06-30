/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:21:58 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 18:21:41 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch_hexa(char *unchange, unsigned int n, char type)
{
	char	*change;
	t_flag	flag;
	int		i;

	flagstore(&flag, unchange);
	if (flag.hash && n)
		change = yeshash(flag, (unsigned long)n);
	else
		change = nohash(flag, (unsigned long)n);
	if (type == 'X')
	{
		i = 0;
		while (change[i])
		{
			change[i] = ft_toupper(change[i]);
			i++;
		}
	}
	return (change);
}

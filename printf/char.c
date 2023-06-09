/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:34 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 13:53:39 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch_char(char *unchange, int c, int *charnul, int ischar)
{
	char	*change;
	t_flag	flag;
	size_t	size;

	flagstore(&flag, unchange);
	size = 1;
	if (ischar && !c)
		*charnul = 1;
	if (flag.xx > 1)
		size = (size_t)flag.xx;
	if (!ischar && !c)
		size = 0;
	change = (char *)malloc(sizeof(char) * (size + 1));
	if (!change)
		return (0);
	change[size] = '\0';
	ft_memset((void *)change, ' ', size);
	if (!(flag.minus) && flag.zero)
		ft_memset((void *)change, '0', size);
	if ((flag.minus && c) || !size)
		change[0] = c;
	else
		change[size - 1] = c;
	return (change);
}

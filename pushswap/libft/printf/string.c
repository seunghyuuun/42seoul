/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:14:18 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/07 21:21:43 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialsetting(char *change, t_flag flag, size_t xsize)
{
	change[xsize] = '\0';
	if (!(flag.minus) && flag.zero)
		ft_memset((void *)change, '0', xsize);
	else
		ft_memset((void *)change, ' ', xsize);
}

char	*ch_str(char *unchange, char *str)
{
	char	*change;
	t_flag	flag;
	size_t	xsize;
	size_t	ysize;

	flagstore(&flag, unchange);
	if (!str)
		str = "(null)";
	ysize = ft_strlen(str);
	if (flag.yy != -1 && ysize > (size_t)flag.yy)
		ysize = (size_t)flag.yy;
	xsize = ysize;
	if (flag.xx != -1 && (size_t)flag.xx > ysize)
		xsize = (size_t)flag.xx;
	change = (char *)malloc(sizeof(char) * (xsize + 1));
	if (!change)
		return (0);
	initialsetting(change, flag, xsize);
	if (flag.minus)
		ft_memcpy((void *)change, (void *)str, ysize);
	else
		ft_memcpy((void *)(&(change[xsize - ysize])), (void *)str, ysize);
	return (change);
}

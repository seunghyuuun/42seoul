/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:55:46 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 18:43:04 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigze(unsigned int n, int flagyy)
{
	int	result;

	result = 0;
	if (!n && flagyy)
		result++;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

void	usitoa(unsigned int n, size_t start, size_t index, char *change)
{
	if (start > index)
		return ;
	change[index] = "0123456789"[n % 10];
	if (index)
		usitoa(n / 10, start, index - 1, change);
}

char	*ch_unsign(char *unchange, unsigned int n)
{
	char	*change;
	t_flag	flag;
	size_t	xsize;
	size_t	ysize;

	flagstore(&flag, unchange);
	ysize = (size_t)unsigze(n, flag.yy);
	if (flag.yy != -1 && ysize < (size_t)flag.yy)
		ysize = (size_t)flag.yy;
	xsize = ysize;
	if (flag.xx != -1 && (size_t)flag.xx > xsize)
		xsize = (size_t)flag.xx;
	change = (char *)malloc(sizeof(char) * (xsize + 1));
	if (!change)
		return (0);
	change[xsize] = '\0';
	ft_memset((void *)change, ' ', xsize);
	if (!(flag.minus) && flag.zero && flag.yy == -1)
		ysize = xsize;
	if (flag.minus && ysize)
		usitoa(n, 0, ysize - 1, change);
	else if (ysize)
		usitoa(n, xsize - ysize, xsize - 1, change);
	return (change);
}

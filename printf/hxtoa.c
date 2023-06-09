/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hxtoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:38:52 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/09 18:33:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hxsize(unsigned long n)
{
	int	result;

	result = 0;
	if (!n)
		result++;
	while (n)
	{
		n = n / 16;
		result++;
	}
	return (result);
}

void	zerox(char *change, int flagminus)
{
	int	i;

	i = 0;
	if (flagminus)
	{
		change[0] = '0';
		change[1] = 'x';
		return ;
	}
	while (change[i] == ' ')
		i++;
	change[i - 1] = 'x';
	change[i - 2] = '0';
}

void	hxtoa(unsigned long n, size_t start, size_t index, char *change)
{
	if (start > index)
		return ;
	change[index] = "0123456789abcdef"[n % 16];
	if (index)
		hxtoa(n / 16, start, index - 1, change);
}

char	*nohash(t_flag flag, unsigned long n)
{
	char	*change;
	size_t	xsize;
	size_t	ysize;

	ysize = (size_t)hxsize(n);
	if (!flag.yy && !n)
		ysize--;
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
		hxtoa(n, 0, ysize - 1, change);
	else if (ysize)
		hxtoa(n, xsize - ysize, xsize - 1, change);
	return (change);
}

char	*yeshash(t_flag flag, unsigned long n)
{
	char	*change;
	size_t	xsize;
	size_t	ysize;

	ysize = (size_t)hxsize(n);
	if (!flag.yy && !n)
		ysize--;
	if (flag.yy != -1 && ysize < (size_t)flag.yy)
		ysize = (size_t)flag.yy;
	xsize = ysize + ft_strlen("0x");
	if (flag.xx != -1 && (size_t)flag.xx > xsize)
		xsize = (size_t)flag.xx;
	change = (char *)malloc(sizeof(char) * (xsize + 1));
	if (!change)
		return (0);
	change[xsize] = '\0';
	ft_memset((void *)change, ' ', xsize);
	if (!(flag.minus) && flag.zero && flag.yy == -1)
		ysize = xsize - ft_strlen("0x");
	if (flag.minus)
		hxtoa(n, 2, 2 + ysize - 1, change);
	else
		hxtoa(n, xsize - ysize, xsize - 1, change);
	zerox(change, flag.minus);
	return (change);
}

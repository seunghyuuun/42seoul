/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demicalint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:19:36 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/14 18:36:36 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ch_xysize(t_flag flag, size_t (*xysize)[2], int n)
{
	size_t	issign;
	size_t	doublezero;

	issign = 0;
	doublezero = 1;
	if (flag.yy || n)
		doublezero = 0;
	(*xysize)[1] -= doublezero;
	if (flag.space || flag.plus || n < 0)
		issign = 1;
	if (flag.yy != -1 && (*xysize)[1] < (size_t)flag.yy)
		(*xysize)[1] = (size_t)flag.yy;
	(*xysize)[0] = (*xysize)[1] + issign;
	if (flag.xx != -1 && (size_t)flag.xx > (*xysize)[0])
		(*xysize)[0] = (size_t)flag.xx;
	if (!(flag.minus) && flag.zero && flag.yy == -1)
		(*xysize)[1] = (*xysize)[0] - issign;
}

void	changesetting(char *change, t_flag flag, size_t xysize[2], char *number)
{
	size_t	issign;
	size_t	signindex;
	size_t	i;
	size_t	zeros;
	size_t	minus;

	issign = 0;
	minus = 0;
	if (number[0] == '-')
		minus = 1;
	if (flag.space || flag.plus || minus)
		issign = 1;
	signindex = xysize[0] - xysize[1] - issign;
	if (flag.minus)
		signindex = 0;
	if (minus)
		change[signindex] = '-';
	else if (issign)
		change[signindex] = '+';
	i = signindex + issign;
	zeros = xysize[1] - (ft_strlen(number) - minus);
	while (zeros-- && xysize[1])
		change[i++] = '0';
	while (number[minus] && (flag.yy || number[0] != '0'))
		change[i++] = number[minus++];
}

void	finalsetting(char *change, t_flag flag, int n)
{
	char	*temp;

	n = 0;
	temp = ft_strchr(change, '+');
	if (!temp)
		return ;
	if (flag.space && !(flag.plus))
		*temp = ' ';
}

char	*ch_int(char *unchange, int n)
{
	char	*change;
	t_flag	flag;
	size_t	xysize[2];
	char	*number;

	flagstore(&flag, unchange);
	number = ft_itoa(n);
	if (!number)
		return (0);
	xysize[1] = ft_strlen(number);
	if (n < 0)
		xysize[1]--;
	ch_xysize(flag, &xysize, n);
	change = (char *)malloc(sizeof(char) * (xysize[0] + 1));
	if (!change)
	{
		free(number);
		return (0);
	}
	change[xysize[0]] = '\0';
	ft_memset((void *)change, ' ', xysize[0]);
	changesetting(change, flag, xysize, number);
	finalsetting(change, flag, n);
	free(number);
	return (change);
}

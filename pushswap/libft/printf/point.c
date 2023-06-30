/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:32:01 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/07 15:33:02 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch_pnt(char *unchange, void *addr)
{
	char	*change;
	t_flag	flag;

	flagstore(&flag, unchange);
	change = yeshash(flag, (unsigned long)addr);
	return (change);
}

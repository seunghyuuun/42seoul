/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:44:34 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 20:03:05 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	endcheck(t_stack *abstack)
{
	t_idata	*temp;
	size_t	bsize;

	if (abstack->atop && abstack->btop && abstack->atop->data < abstack->btop->data)
		return ;
	temp = abstack->atop;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return ;
		temp = temp->next;
	}
	bsize = 1;
	temp = abstack->btop;
	while (temp && temp->next)
	{
		if (temp->data < temp->next->data)
			return ;
		temp = temp->next;
		bsize++;
	}
	npusha(abstack, bsize);
	allstackfree(abstack);
	exit(0);
}

void	errorend(t_stack *abstack)
{
	allstackfree(abstack);
	ft_printf("Error\n");
	exit (-1);
}

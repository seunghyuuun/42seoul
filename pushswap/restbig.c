/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:36:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 14:36:53 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigfloor(t_stack *abstack, size_t size)
{
	t_idata *temp;

	if (size < 2)
		return ;
	temp = abstack->atop->next;
	if (abstack->atop->data > temp->data)
		comcall(ps_swap, abstack, 'a');
}

void	restbig(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	regular;
	size_t	large;
	size_t	max;
	size_t	i;

	if (size < 3)
	{
		bigfloor(abstack, size);
		return ;
	}
	pivotmaker(abstack->atop, size, pivot);
	if (!(pivot[0]) && !(pivot[1]))
		errorend(abstack);
	regular = 0;
	large = 0;
	max = 0;
	while (regular + large + max < size)
	{
		if (abstack->atop->data >= pivot[1])
		{
			comcall(ps_rotate, abstack, 'a');
			max++;
		}
		else if (abstack->atop->data > pivot[0])
		{
			comcall(ps_push, abstack, 'b');
			comcall(ps_rotate, abstack, 'b');
			large++;
		}
		else
		{
			comcall(ps_push, abstack, 'b');
			regular++;
		}
	}
	i = 0;
	while (i < max || i < large)
	{
		if (i < max && i < large)
			comcall(ps_revrotate, abstack, 'a' + 'b');
		else if (i < max)
			comcall(ps_revrotate, abstack, 'a');
		else
			comcall(ps_revrotate, abstack, 'b');
		i++;
	}
	restbig(abstack, max);
	restsmall(abstack, large);
	restsmall(abstack, regular);
}

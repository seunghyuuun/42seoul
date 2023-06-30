/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:27:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 16:27:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallfloor(t_stack *abstack, size_t size)
{
	t_idata *temp;

	if (!size)
		return ;
	if (size == 2)
	{
		temp = abstack->btop->next;
		if (abstack->btop->data < temp->data)
			comcall(ps_swap, abstack, 'b');
	}
	comcall(ps_push, abstack, 'a');
	while (--size)
		comcall(ps_push, abstack, 'a');
}

void	restsmall(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	regular;
	size_t	large;
	size_t	max;
	size_t	i;

	if (size < 3)
	{
		smallfloor(abstack, size);
		return ;
	}
	pivotmaker(abstack->btop, size, pivot);
	if (!(pivot[0]) && !(pivot[1]))
		errorend(abstack);
	regular = 0;
	large = 0;
	max = 0;
	while (regular + large + max < size)
	{
		if (abstack->btop->data >= pivot[1])
		{
			comcall(ps_push, abstack, 'a');
			max++;
		}
		else if (abstack->btop->data > pivot[0])
		{
			comcall(ps_push, abstack, 'a');
			comcall(ps_rotate, abstack, 'a');
			large++;
		}
		else
		{
			comcall(ps_rotate, abstack, 'b');
			regular++;
		}
	}
	restbig(abstack, max);
	i = 0;
	while (i < regular || i < large)
	{
		if (i < regular && i < large)
			comcall(ps_revrotate, abstack, 'a' + 'b');
		else if (i < large)
			comcall(ps_revrotate, abstack, 'a');
		else
			comcall(ps_revrotate, abstack, 'b');
		i++;
	}
	restbig(abstack, large);
	restsmall(abstack, regular);
}

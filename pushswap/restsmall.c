/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:27:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 20:44:52 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallfloor(t_stack *abstack, size_t size)
{
	t_idata	*temp;

	if (size == 2)
	{
		temp = abstack->btop->next;
		if (abstack->btop->data < temp->data)
			comcall(ps_swap, abstack, 'b');
	}
	npusha(abstack, size);
}

void	trisect_small(t_stack *abstack, int pivot[2], size_t sml[3], size_t size)
{
	while (sml[0] + sml[1] + sml[2] < size)
	{
		endcheck(abstack);
		if (abstack->btop->data >= pivot[1])
		{
			comcall(ps_push, abstack, 'a');
			sml[2]++;
		}
		else if (abstack->btop->data > pivot[0])
		{
			comcall(ps_push, abstack, 'a');
			comcall(ps_rotate, abstack, 'a');
			sml[1]++;
		}
		else
		{
			comcall(ps_rotate, abstack, 'b');
			sml[0]++;
		}
	}
}

void	restsmall(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	sml[3];

	if (size < 3)
	{
		smallfloor(abstack, size);
		return ;
	}
	pivotmaker(abstack->btop, size, pivot);
	if (!(pivot[0]) && !(pivot[1]))
		errorend(abstack);
	sml[0] = 0;
	sml[1] = 0;
	sml[2] = 0;
	trisect_small(abstack, pivot, sml, size);
	restbig(abstack, sml[2]);
	nnrrab(abstack, sml[1], sml[0]);
	restbig(abstack, sml[1]);
	restsmall(abstack, sml[0]);
}

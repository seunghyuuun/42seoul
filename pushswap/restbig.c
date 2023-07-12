/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:36:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/11 13:05:12 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigthree(t_stack *abstack)
{
	int	triple[3];

	triple[0] = abstack->atop->data;
	triple[1] = abstack->atop->next->data;
	triple[2] = abstack->atop->next->next->data;
	if (triple[2] > triple[0] && triple[2] > triple[1])
		return ;
	if (triple[0] > triple[1])
		comcall(ps_swap, abstack, 'a');
	comcall(ps_rotate, abstack, 'a');
	comcall(ps_swap, abstack, 'a');
	comcall(ps_revrotate, abstack, 'a');
}

void	bigfloor(t_stack *abstack, size_t size)
{
	t_idata	*temp;

	if (size < 2)
		return ;
	if (size == 3)
		bigthree(abstack);
	temp = abstack->atop->next;
	if (abstack->atop->data > temp->data)
		comcall(ps_swap, abstack, 'a');
}

void	trisect_big(t_stack *abstack, int pivot[2], size_t sml[3], size_t size)
{
	while (sml[0] + sml[1] + sml[2] < size)
	{
		if (endcheck(abstack))
		{
			npusha(abstack, endcheck(abstack));
			allstackfree(abstack);
			exit(0);
		}
		if (abstack->atop->data >= pivot[1])
			sml[2] += comcall(ps_rotate, abstack, 'a');
		else if (abstack->atop->data > pivot[0])
		{
			sml[1] += comcall(ps_push, abstack, 'b');
			if (sml[0] + sml[1] + sml[2] < size \
					&& abstack->atop->data >= pivot[1])
				sml[2] += comcall(ps_rotate, abstack, 'a' + 'b');
			else
				comcall(ps_rotate, abstack, 'b');
		}
		else
			sml[0] += comcall(ps_push, abstack, 'b');
	}
}

void	restbig(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	sml[3];

	if (size < 4)
	{
		bigfloor(abstack, size);
		return ;
	}
	pivotmaker(abstack->atop, size, pivot);
	if (!(pivot[0]) && !(pivot[1]))
		errorend(abstack);
	sml[0] = 0;
	sml[1] = 0;
	sml[2] = 0;
	trisect_big(abstack, pivot, sml, size);
	nnrrab(abstack, sml[2], sml[1]);
	restbig(abstack, sml[2]);
	restsmall(abstack, sml[1]);
	restsmall(abstack, sml[0]);
}

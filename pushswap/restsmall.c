/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:27:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 21:22:53 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void smallthree(t_stack *abstack)
{
	int triple[3];

	triple[0] = abstack->btop->data;
	triple[1] = abstack->btop->next->data;
	triple[2] = abstack->btop->next->next->data;
	if (triple[2] < triple[0] && triple[2] < triple[1])
		return ;
	if (triple[0] < triple[1])
		comcall(ps_swap, abstack, 'b');
	comcall(ps_rotate, abstack, 'b');
	comcall(ps_swap, abstack, 'b');
	comcall(ps_revrotate, abstack, 'b');
}

void	smallfloor(t_stack *abstack, size_t size)
{
	t_idata	*temp;

	if (size == 3)
		smallthree(abstack);
	if (size > 1)
	{
		temp = abstack->btop->next;
		if (abstack->btop->data < temp->data)
			comcall(ps_swap, abstack, 'b');
	}
	npusha(abstack, size);
}

void	trisect_sm(t_stack *abstack, int pivot[2], size_t sml[3], size_t size)
{
	while (sml[0] + sml[1] + sml[2] < size)
	{
		if (endcheck(abstack))
		{
			npusha(abstack, endcheck(abstack));
			allstackfree(abstack);
			exit(0);
		}
		if (abstack->btop->data >= pivot[1])
			sml[2] += comcall(ps_push, abstack, 'a');
		else if (abstack->btop->data > pivot[0])
		{
			sml[1] += comcall(ps_push, abstack, 'a');
			if (sml[0] + sml[1] + sml[2] < size && abstack->btop->data <= pivot[0])
				sml [0] += comcall(ps_rotate, abstack, 'a' + 'b');
			else
				comcall(ps_rotate, abstack, 'a');
		}
		else
			sml [0] += comcall(ps_rotate, abstack, 'b');
	}
}

void	restsmall(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	sml[3];

	if (size < 4)
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
	trisect_sm(abstack, pivot, sml, size);
	restbig(abstack, sml[2]);
	nnrrab(abstack, sml[1], sml[0]);
	restbig(abstack, sml[1]);
	restsmall(abstack, sml[0]);
}

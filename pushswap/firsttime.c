/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firsttime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:36:17 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/11 13:04:02 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	threesize(t_stack *abstack)
{
	int		data[3];
	size_t	i;
	t_idata	*temp;

	i = 0;
	temp = abstack->atop;
	while (i < 3)
	{
		data[i] = temp->data;
		i++;
		temp = temp->next;
	}
	if (data[0] > data[1] && data[0] > data[2])
		comcall(ps_rotate, abstack, 'a');
	else if (data[1] > data[0] && data[1] > data[2])
		comcall(ps_revrotate, abstack, 'a');
	if (abstack->atop->data > abstack->atop->next->data)
		comcall(ps_swap, abstack, 'a');
}

void	trisect_fst(t_stack *abstack, int pivot[2], size_t sml[3], size_t size)
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
		else if (abstack->atop->data <= pivot[0])
		{
			sml[0] += comcall(ps_push, abstack, 'b');
			if (sml[1])
			{
				if (sml[0] + sml[1] + sml[2] < size \
						&& abstack->atop->data >= pivot[1])
					sml[2] += comcall(ps_rotate, abstack, 'a' + 'b');
				else
					comcall(ps_rotate, abstack, 'b');
			}
		}
		else
			sml[1] += comcall(ps_push, abstack, 'b');
	}
}

void	firsttime(t_stack *abstack, size_t size)
{
	int		pivot[2];
	size_t	sml[3];

	if (size < 3)
	{
		bigfloor(abstack, size);
		return ;
	}
	else if (size == 3)
	{
		threesize(abstack);
		return ;
	}
	pivotmaker(abstack->atop, size, pivot);
	if (!(pivot[0]) && !(pivot[1]))
		errorend(abstack);
	sml[0] = 0;
	sml[1] = 0;
	sml[2] = 0;
	trisect_fst(abstack, pivot, sml, size);
	restbig(abstack, sml[2]);
	restsmall(abstack, sml[1]);
	restsmall(abstack, sml[0]);
}

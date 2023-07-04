/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:18:22 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 15:56:46 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *abstack, int c)
{
	size_t	size;
	t_idata	*second;

	if (c == 'a' || c == 'a' + 'b')
	{
		size = stacksize(abstack->atop);
		if (size > 1)
		{
			second = abstack->atop->next;
			stackout(abstack, second, 'a');
			stacktop(abstack, second, 'a');
		}
	}
	if (c == 'b' || c == 'a' + 'b')
	{
		size = stacksize(abstack->btop);
		if (size > 1)
		{
			second = abstack->btop->next;
			stackout(abstack, second, 'b');
			stacktop(abstack, second, 'b');
		}
	}
}

void	ps_push(t_stack *abstack, int c)
{
	size_t	size;
	t_idata	*node;

	if (c == 'a')
	{
		size = stacksize(abstack->btop);
		if (size > 0)
		{
			node = abstack->btop;
			stackout(abstack, node, 'b');
			stacktop(abstack, node, 'a');
		}
	}
	else if (c == 'b')
	{
		size = stacksize(abstack->atop);
		if (size > 0)
		{
			node = abstack->atop;
			stackout(abstack, node, 'a');
			stacktop(abstack, node, 'b');
		}
	}
}

void	ps_rotate(t_stack *abstack, int c)
{
	size_t	size;
	t_idata	*first;

	if (c == 'a' || c == 'a' + 'b')
	{
		size = stacksize(abstack->atop);
		if (size > 1)
		{
			first = abstack->atop;
			stackout(abstack, first, 'a');
			stackbottom(abstack, first, 'a');
		}
	}
	if (c == 'b' || c == 'a' + 'b')
	{
		size = stacksize(abstack->btop);
		if (size > 1)
		{
			first = abstack->btop;
			stackout(abstack, first, 'b');
			stackbottom(abstack, first, 'b');
		}
	}
}

void	ps_revrotate(t_stack *abstack, int c)
{
	size_t	size;
	t_idata	*last;

	if (c == 'a' || c == 'a' + 'b')
	{
		size = stacksize(abstack->atop);
		if (size > 1)
		{
			last = abstack->abottom;
			stackout(abstack, last, 'a');
			stacktop(abstack, last, 'a');
		}
	}
	if (c == 'b' || c == 'a' + 'b')
	{
		size = stacksize(abstack->btop);
		if (size > 1)
		{
			last = abstack->bbottom;
			stackout(abstack, last, 'b');
			stacktop(abstack, last, 'b');
		}
	}
}

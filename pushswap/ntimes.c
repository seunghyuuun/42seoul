/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntimes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:17:11 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 20:02:39 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	biggerone(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

void	npusha(t_stack *abstack, size_t n)
{
	size_t	doing;

	doing = 0;
	if (!(abstack->btop))
		return ;
	while (doing < n)
	{
		comcall(ps_push, abstack, 'a');
		doing++;
	}
}

void	npsab(t_stack *abstack, void (*ps)(t_stack*, int), size_t na, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < na || i < nb)
	{
		if (i < na && i < nb)
			comcall(ps, abstack, 'a' + 'b');
		else if (i < na)
			comcall(ps, abstack, 'a');
		else
			comcall(ps, abstack, 'b');
		i++;
	}
}

void	nnrrab(t_stack *abstack, size_t nrra, size_t nrrb)
{
	size_t	nra;
	size_t	nrb;

	nra = stacksize(abstack->atop) - nrra;
	nrb = stacksize(abstack->btop) - nrrb;
	if (!nrra)
		nra = 0;
	if (!nrrb)
		nrb = 0;
	if (!nra)
		nrra = 0;
	if (!nrb)
		nrrb = 0;
	if (biggerone(nra, nrb) < biggerone(nrra, nrrb))
		npsab(abstack, ps_rotate, nra, nrb);
	else
		npsab(abstack, ps_revrotate, nrra, nrrb);
}

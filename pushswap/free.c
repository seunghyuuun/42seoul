/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:24:56 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 14:26:01 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allstackfree(t_stack *abstack)
{
	t_idata	*cage;
	t_idata	*bird;

	cage = abstack->atop;
	while (cage)
	{
		bird = cage;
		cage = cage->next;
		free(bird);
	}
	cage = abstack->btop;
	while (cage)
	{
		bird = cage;
		cage = cage->next;
		free(bird);
	}
}

void	twodfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:34:27 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/30 14:35:34 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	framesetting(t_idata **temp, int *frame, size_t third)
{
	size_t	i;

	i = 0;
	while (i < third)
	{
		frame[i] = (*temp)->data;
		(*temp) = (*temp)->next;
		i++;
	}
}

size_t	most_index(int *frame, size_t third, int bigsmallflag)
{
	size_t	i;
	size_t	save;

	i = 0;
	save = 0;
	if (bigsmallflag)
	{
		while (i < third)
		{
			if (frame[save] < frame[i])
				save = i;
			i++;
		}
	}
	else
	{
		while (i < third)
		{
			if (frame[save] > frame[i])
				save = i;
			i++;
		}
	}
	return (save);
}

int	firstpivot(t_idata *temp, int *frame, size_t third, size_t size)
{
	int		result;
	size_t	most;
	size_t	i;

	i = third;
	while (i < size)
	{
		result = temp->data;
		most = most_index(frame, third, 1);
		if (result < frame[most])
			frame[most] = result;
		temp = temp->next;
		i++;
	}
	most = most_index(frame, third, 1);
	result = frame[most];
	return (result);
}

int	secondpivot(t_idata *temp, int *frame, size_t third, size_t size)
{
	int		result;
	size_t	most;
	size_t	i;

	i = third;
	while (i < size)
	{
		result = temp->data;
		most = most_index(frame, third, 0);
		if (result > frame[most])
			frame[most] = result;
		temp = temp->next;
		i++;
	}
	most = most_index(frame, third, 0);
	result = frame[most];
	return (result);
}

void	pivotmaker(t_idata *top, size_t size, int pivot[2])
{
	t_idata	*temp;
	int		*frame;
	size_t	third;

	third = size / 3;
	if (size % 3 == 2)
		third = (size + 1) / 3;
	frame = (int *)malloc(sizeof(int) * (third));
	if (!frame)
	{
		pivot[0] = 0;
		pivot[1] = 0;
		return ;
	}
	temp = top;
	framesetting(&temp, frame, third);
	pivot[0] = firstpivot(temp, frame, third, size);
	temp = top;
	framesetting(&temp, frame, third);
	pivot[1] = secondpivot(temp, frame, third, size);
	free(frame);
}

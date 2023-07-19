/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:38:44 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 16:39:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	indexset(unsigned int i, unsigned int num_of_phil)
{
	if (i == num_of_phil)
		return (0);
	return (i);
}

unsigned int	timegap(struct timeval start, struct timeval end)
{
	unsigned long long	sec;
	unsigned int		mil;

	sec = end.tv_sec - start.tv_sec;
	mil = (unsigned int)sec * 1000000 + end.tv_usec - start.tv_usec;
	return (mil);
}

unsigned int	sch_timegap(struct timeval start, struct timeval end)
{
	unsigned long long	sec;
	unsigned int		mil;

	sec = end.tv_sec - start.tv_sec;
	mil = (unsigned int)sec * 1000000 + end.tv_usec - start.tv_usec;
	return (mil);
}

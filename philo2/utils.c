/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:13:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/02 15:11:03 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timegap(struct timeval start, struct timeval present)
{
	unsigned long long	sec;
	unsigned int		mil;

	sec = present.tv_sec - start.tv_sec;
	mil = (unsigned int)sec * 1000000 + present.tv_usec - start.tv_usec;
	return (mil);
}

void	napping(unsigned int sleep, struct timeval start)
{
	unsigned int	gap;
	struct timeval	present;

	gap = 0;
	while (gap < sleep)
	{
		usleep(10);
		gettimeofday(&present, 0);
		gap = timegap(start, present);
	}
}

void	ph_notice(t_phil *philone, struct timeval present, char *str)
{
	unsigned int	gap;
	struct timeval	start;

	if (philone->rule->end)
		return ;
	start = philone->rule->start;
	gap = timegap(start, present);
	pthread_mutex_lock(&(philone->rule->notice));
	if (!(philone->rule->end))
		printf("%u %u %s\n", gap, (philone->index) + 1, str);
	pthread_mutex_unlock(&(philone->rule->notice));
}

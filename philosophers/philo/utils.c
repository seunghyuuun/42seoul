/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:13:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 14:22:11 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timegap(struct timeval start, struct timeval present)
{
	long				sec;
	unsigned int		mic;

	if (start.tv_sec > present.tv_sec)
		return (0);
	sec = present.tv_sec - start.tv_sec;
	mic = ((unsigned int)sec) * 1000;
	if (!mic && start.tv_usec >= present.tv_usec)
		return (0);
	mic += (present.tv_usec - start.tv_usec) / 1000;
	return (mic);
}

void	napping(unsigned int sleep, struct timeval start, t_phil *philone)
{
	unsigned int	gap;
	struct timeval	present;

	gap = 0;
	while (!(endmutexcheck(philone->rule)) && gap < sleep)
	{
		usleep(200);
		gettimeofday(&present, 0);
		gap = timegap(start, present);
	}
}

void	ph_notice(t_phil *philone, char *str)
{
	unsigned int	gap;
	struct timeval	start;
	struct timeval	present;

	if (endmutexcheck(philone->rule))
		return ;
	start = philone->rule->start;
	pthread_mutex_lock(&(philone->rule->notice));
	gettimeofday(&present, 0);
	gap = timegap(start, present);
	if (!(endmutexcheck(philone->rule)))
		printf("%u %u %s\n", gap, (philone->index) + 1, str);
	pthread_mutex_unlock(&(philone->rule->notice));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:13:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/08 19:19:10 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timegap(struct timeval start, struct timeval present)
{
	long				sec;
	int					temp;
	unsigned int		mic;

	if (start.tv_sec > present.tv_sec)
		return (0);
	sec = present.tv_sec - start.tv_sec;
	mic = ((unsigned int)sec) * 1000;
	if (!mic && start.tv_usec >= present.tv_usec)
		return (0);
	mic += (present.tv_usec - start.tv_usec) / 1000;
	temp = ((int)(present.tv_usec - start.tv_usec)) % 1000;
	if (temp > 800)
		mic++;
	else if (temp < -200)
		mic--;
	return (mic);
}

void	napping(unsigned int sleep, struct timeval start, t_phil *philone)
{
	unsigned int	gap;
	struct timeval	present;

	gap = 0;
	while (!(philone->rule->end) && gap < sleep)
	{
		usleep(200);
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

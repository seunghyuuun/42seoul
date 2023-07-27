/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/27 16:32:09 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	napping(unsigned int sleep)
{
	unsigned int	gap;
	struct timeval	present;
	struct timeval	start;

	gettimeofday(&start, 0);
	gap = 0;
	while (gap <= sleep)
	{
		usleep(5);
		gettimeofday(&present, 0);
		gap = timegap(start, present);
	}
}

void	ph_notice(t_phil *philone, char *str)
{
	unsigned int	gap;
	struct timeval	start;
	struct timeval	present;

	if (philone->rule->dead)
		return ;
	gettimeofday(&present, 0);
	start = philone->rule->start;
	gap = timegap(start, present);
	pthread_mutex_lock(&(philone->rule->notice));
	if (!(philone->rule->dead))
		printf("%u %u %s\n", gap, (philone->index) + 1, str);
	pthread_mutex_unlock(&(philone->rule->notice));
}

void	ph_eat(t_phil *philone)
{
	pthread_mutex_t	*fork;
	unsigned int	index;

	fork = philone->rule->fork;
	index = philone->index;
	pthread_mutex_lock(&(fork[index]));
	ph_notice(philone, "has taken a fork");
	pthread_mutex_lock(&(fork[(index + 1) % philone->rule->num_of_phil]));
	gettimeofday(&(philone->eat), 0);
	ph_notice(philone, "has taken a fork");
	ph_notice(philone, "is eating");
	(philone->eatnum)++;
	napping(philone->rule->time_to_eat);
	pthread_mutex_unlock(&(fork[(index + 1) % philone->rule->num_of_phil]));
	pthread_mutex_unlock(&(fork[index]));
}

void	*ph_schedul(void *phil)
{
	t_phil	*philone;

	philone = (t_phil *)phil;
	if ((philone->index) % 2 == 0)
		napping((philone->rule->time_to_eat) * 1);
	while (!(philone->rule->dead) && !(philone->rule->end))
	{
		ph_eat(philone);
		ph_notice(philone, "is sleeping");
		if (!(philone->rule->dead))
			napping(philone->rule->time_to_sleep);
		ph_notice(philone, "is thinking");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/24 19:59:43 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_notice(t_phil *philone, char *str)
{
	unsigned long long	sec;
	unsigned int		mil;
	struct timeval		present;
	struct timeval		start;

	pthread_mutex_lock(&(philone->rule->notice));
	start = philone->rule->start;
	gettimeofday(&present, 0);
	sec = present.tv_sec - start.tv_sec;
	mil = (unsigned int)sec * 1000000 + present.tv_usec - start.tv_usec;
	printf("%u %u %s\n", mil, (philone->index) + 1, str);
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
	ph_notice(philone, "has taken a fork");
	ph_notice(philone, "is eating");
	(philone->eatnum)++;
	gettimeofday(&(philone->eat), 0);
	usleep(philone->rule->time_to_eat);
	pthread_mutex_unlock(&(fork[(index + 1) % philone->rule->num_of_phil]));
	pthread_mutex_unlock(&(fork[index]));
}

void	*ph_schedul(void *phil)
{
	t_phil	*philone;

	philone = (t_phil *)phil;
	if ((philone->index) % 2 == 0)
		usleep((philone->rule->time_to_eat) * 3);
	while (philone->eatnum < philone->rule->must_eat)
	{
		ph_eat(philone);
		ph_notice(philone, "is sleeping");
		usleep(philone->rule->time_to_sleep);
		ph_notice(philone, "is thinking");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/28 17:20:57 by seunghy2         ###   ########.fr       */
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
	while (gap < sleep)
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

	if (philone->rule->dead || philone->rule->end)
		return ;
	gettimeofday(&present, 0);
	start = philone->rule->start;
	gap = timegap(start, present);
	if (!(philone->rule->dead) && !(philone->rule->end))
	{
		pthread_mutex_lock(&(philone->rule->notice));
		printf("%u %u %s\n", gap, (philone->index) + 1, str);
		pthread_mutex_unlock(&(philone->rule->notice));
	}
}
/*
void	ph_eat(t_phil *philone)
{
	pthread_mutex_t	*fork;
	unsigned int	index;

	fork = philone->rule->fork;
	index = philone->index;
	pthread_mutex_lock(&(fork[index]));
	ph_notice(philone, "has taken a fork");
	pthread_mutex_lock(&(fork[(index + 1) % philone->rule->num_of_phil]));
	usleep(1);
	ph_notice(philone, "has taken a fork");
	usleep(1); 
	gettimeofday(&(philone->eat), 0);
	ph_notice(philone, "is eating");
	(philone->eatnum)++;
	napping(philone->rule->time_to_eat);
	pthread_mutex_unlock(&(fork[(index + 1) % philone->rule->num_of_phil]));
	pthread_mutex_unlock(&(fork[index]));
}*/

int	ph_left(t_phil *philone)
{
	unsigned int	*forks;
	unsigned int	index;

	if (philone->rule->dead || philone->rule->end)
		return (1);
	forks = philone->rule->forks;
	index = philone->index;
	pthread_mutex_lock(&(philone->rule->pick_fork));
	if (forks[index])
	{
		pthread_mutex_unlock(&(philone->rule->pick_fork));
		return (0);
	}
	forks[index] = 1;
	pthread_mutex_unlock(&(philone->rule->pick_fork));
	ph_notice(philone, "has taken a fork");
	return (1);
}	

int	ph_right(t_phil *philone)
{
	unsigned int	*forks;
	unsigned int	index;

	if (philone->rule->dead || philone->rule->end)
		return (1);
	forks = philone->rule->forks;
	index = ((philone->index) + 1) % philone->rule->num_of_phil;
	pthread_mutex_lock(&(philone->rule->pick_fork));
	if (forks[index])
	{
		pthread_mutex_unlock(&(philone->rule->pick_fork));
		return (0);
	}
	forks[index] = 1;
	pthread_mutex_unlock(&(philone->rule->pick_fork));
	ph_notice(philone, "has taken a fork");
	return (1);
}

void	*ph_schedul(void *phil)
{
	t_phil	*philone;
	unsigned int	index;
	unsigned int	*forks;

	philone = (t_phil *)phil;
	index = philone->index;
	forks = philone->rule->forks;
	if ((philone->index) % 2 == 0)
		napping((philone->rule->time_to_eat) / 10);
	while (!(philone->rule->dead) && !(philone->rule->end))
	{
		while (!(ph_left(philone)));
		//usleep(1);
		while (!(ph_right(philone)));
		//usleep(1);
		(philone->eatnum)++;
		gettimeofday(&(philone->eat), 0);
		ph_notice(philone, "is eating");
		if (!(philone->rule->dead) && !(philone->rule->end))
			napping(philone->rule->time_to_eat);
		forks[(index + 1) % philone->rule->num_of_phil] = 0;
		forks[index] = 0;
		ph_notice(philone, "is sleeping");
		if (!(philone->rule->dead) && !(philone->rule->end))
			napping(philone->rule->time_to_sleep);
		ph_notice(philone, "is thinking");
	}
	return (0);
}

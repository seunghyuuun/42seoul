/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:35:18 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 16:38:38 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleependcheck(t_phil *philone)
{
	unsigned int		i;
	int					*fork;
	struct timeval		time;
	unsigned long long	sec;
	unsigned int		mil;

	i = philone->index;
	fork = philone->rules->forks;
	gettimeofday(&time, 0);
	sec = time.tv_sec - philone->sleep.tv_sec;
	mil = (unsigned int)sec * 1000000 + time.tv_usec - philone->sleep.tv_usec;
	if (mil >= philone->rules->time_to_sleep)
	{
		philone->status = THINK;
		philone->renewal = 1;
	}
}

void	eatendcheck(t_phil *philone)
{
	unsigned int		i;
	int					*fork;
	struct timeval		time;
	unsigned long long	sec;
	unsigned int		mil;

	i = philone->index;
	fork = philone->rules->forks;
	gettimeofday(&time, 0);
	sec = time.tv_sec - philone->eat.tv_sec;
	mil = (unsigned int)sec * 1000000 + time.tv_usec - philone->eat.tv_usec;
	if (mil >= philone->rules->time_to_eat)
	{
		fork[i] = 1;
		fork[indexset(i + 1, philone->rules->num_of_phil)] = 1;
		philone->status = SLEEP;
		philone->renewal = 1;
		gettimeofday(&(philone->sleep), 0);
	}
}

void	eatablecheck(t_phil *philone)
{
	unsigned int	i;
	int				*fork;

	i = philone->index;
	fork = philone->rules->forks;
	if (fork[i] == 1 && fork[indexset(i + 1, philone->rules->num_of_phil)] == 1)
	{
		fork[i] = 0;
		fork[indexset(i + 1, philone->rules->num_of_phil)] = 0;
		philone->status = EAT;
		philone->renewal = 1;
		gettimeofday(&(philone->eat), 0);
	}
	else if (!(philone->status) && !(sch_timegap(philone->eat, philone->rules->start)))
	{
		philone->status = THINK;
		philone->renewal = 1;
	}
}

int	ph_iternal(void *phil)
{
	t_phil				*philone;
	struct timeval		time;
	unsigned long long	sec;
	unsigned int		mil;

	pthread_mutex_lock(&(((t_phil *)phil)->rules->mutex));
	philone = (t_phil *)phil;
	gettimeofday(&time, 0);
	sec = time.tv_sec - philone->eat.tv_sec;
	mil = (unsigned int)sec * 1000000 + time.tv_usec - philone->eat.tv_usec;
	if (mil >= philone->rules->time_to_die)
	{
		pthread_mutex_unlock(&(philone->rules->mutex));
		return (0);
	}
	if (philone->status == 0 || philone->status == THINK)
		eatablecheck(philone);
	else if (philone->status == EAT)
		eatendcheck(philone);
	else
		sleependcheck(philone);
	pthread_mutex_unlock(&(philone->rules->mutex));
	return (1);
}

void	*ph_schedul(void *phil)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = ph_iternal(phil);
	}
	return (0);
}

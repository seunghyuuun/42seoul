/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:57 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_fork(t_phil *philone, int leftright)
{
	t_fork			*forks;
	unsigned int	index;

	if (endmutexcheck(philone->rule))
		return (1);
	forks = philone->rule->forks;
	index = philone->index;
	if (!leftright)
		index = (index + 1) % philone->rule->num_of_phil;
	pthread_mutex_lock(&((forks[index]).fkmtx));
	if ((forks[index]).fkuse)
	{
		pthread_mutex_unlock(&((forks[index]).fkmtx));
		return (0);
	}
	(forks[index]).fkuse = 1;
	pthread_mutex_unlock(&((forks[index]).fkmtx));
	ph_notice(philone, "has taken a fork");
	return (1);
}

void	ph_eat(t_phil *philone)
{
	unsigned int	index;
	t_fork			*forks;
	struct timeval	eattime;

	forks = philone->rule->forks;
	index = ((philone->index) + 1) % philone->rule->num_of_phil;
	while (!(ph_fork(philone, 1)))
		;
	while (!(ph_fork(philone, 0)))
		;
	if (endmutexcheck(philone->rule))
		return ;
	pthread_mutex_lock(&(philone->eatmutex));
	ph_notice(philone, "is eating");
	(philone->eatnum)++;
	gettimeofday(&(philone->eat), 0);
	eattime = philone->eat;
	pthread_mutex_unlock(&(philone->eatmutex));
	napping(philone->rule->time_to_eat, eattime, philone);
	pthread_mutex_lock(&((forks[index]).fkmtx));
	(forks[index]).fkuse = 0;
	pthread_mutex_unlock(&((forks[index]).fkmtx));
	pthread_mutex_lock(&((forks[philone->index]).fkmtx));
	(forks[philone->index]).fkuse = 0;
	pthread_mutex_unlock(&((forks[philone->index]).fkmtx));
}

void	ph_sleep(t_phil *philone)
{
	struct timeval	present;

	gettimeofday(&present, 0);
	ph_notice(philone, "is sleeping");
	napping(philone->rule->time_to_sleep, present, philone);
}

void	ph_think(t_phil *philone)
{
	ph_notice(philone, "is thinking");
}

void	*ph_schedul(void *phil)
{
	t_phil			*philone;
	void			(*ph[3])(t_phil *);
	unsigned int	i;

	philone = (t_phil *)phil;
	ph[0] = ph_eat;
	ph[1] = ph_sleep;
	ph[2] = ph_think;
	while (!((philone->rule->start).tv_sec))
		;
	if (philone->index % 2 == 1)
		napping((philone->rule->time_to_eat), philone->rule->start, philone);
	while (1)
	{
		i = 0;
		while (i < 3 && !(endmutexcheck(philone->rule)))
		{
			ph[i](philone);
			i++;
		}
		if (i != 3)
			break ;
	}
	return (0);
}

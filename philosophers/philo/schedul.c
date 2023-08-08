/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:20:10 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/08 15:37:29 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_fork(t_phil *philone, int leftright)
{
	unsigned int	*forks;
	unsigned int	index;
	struct timeval	present;

	if (philone->rule->end)
		return (1);
	forks = philone->rule->forks;
	index = philone->index;
	if (!leftright)
		index = (index + 1) % philone->rule->num_of_phil;
	pthread_mutex_lock(&(philone->rule->pick_fork));
	if (forks[index])
	{
		pthread_mutex_unlock(&(philone->rule->pick_fork));
		return (0);
	}
	forks[index] = 1;
	pthread_mutex_unlock(&(philone->rule->pick_fork));
	gettimeofday(&present, 0);
	ph_notice(philone, present, "has taken a fork");
	return (1);
}

void	ph_eat(t_phil *philone)
{
	unsigned int	index;
	unsigned int	*forks;

	index = philone->index;
	forks = philone->rule->forks;
	while (!(ph_fork(philone, 1)))
		;
	while (!(ph_fork(philone, 0)))
		;
	(philone->eatnum)++;
	gettimeofday(&(philone->eat), 0);
	ph_notice(philone, philone->eat, "is eating");
	napping(philone->rule->time_to_eat, philone->eat, philone);
	forks[(index + 1) % philone->rule->num_of_phil] = 0;
	forks[index] = 0;
}

void	ph_sleep(t_phil *philone)
{
	struct timeval	present;

	gettimeofday(&present, 0);
	ph_notice(philone, present, "is sleeping");
	napping(philone->rule->time_to_sleep, present, philone);
}

void	ph_think(t_phil *philone)
{
	struct timeval	present;

	gettimeofday(&present, 0);
	ph_notice(philone, present, "is thinking");
}

void	*ph_schedul(void *phil)
{
	t_phil			*philone;
	void			(*ph[3])(t_phil *);
	unsigned int	i;
	unsigned int	keepgo;

	philone = (t_phil *)phil;
	keepgo = 1;
	ph[0] = ph_eat;
	ph[1] = ph_sleep;
	ph[2] = ph_think;
	if (philone->index % 2 == 1)
		napping((philone->rule->time_to_eat), philone->rule->start, philone);
	while (keepgo)
	{
		keepgo = 0;
		i = 0;
		while (i < 3 && !(philone->rule->end))
		{
			ph[i](philone);
			i++;
		}
		if (i == 3)
			keepgo = 1;
	}
	return (0);
}

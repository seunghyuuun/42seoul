/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:40:13 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/18 19:19:02 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allfree(t_rule *rule, int mutexinit, t_phil *philist, unsigned int mi)
{
	unsigned int	i;

	free(rule->forks);
	if (mutexinit > 2)
		pthread_mutex_destroy(&(rule->endmutex));
	if (mutexinit > 1)
		pthread_mutex_destroy(&(rule->notice));
	if (mutexinit)
		pthread_mutex_destroy(&(rule->pick_fork));
	if (!philist)
		return (-1);
	i = 0;
	while (i < mi)
	{
		pthread_mutex_destroy(&(philist[i].eatmutex));
		i++;
	}
	free(philist);
	return (-1);
}

unsigned int	eatnumcheck(t_phil *philist, unsigned int i)
{
	t_rule	*rule;

	rule = philist->rule;
	pthread_mutex_lock(&(philist[i].eatmutex));
	if ((philist[i]).eatnum >= rule->must_eat)
	{
		pthread_mutex_unlock(&(philist[i].eatmutex));
		return (1);
	}
	pthread_mutex_unlock(&(philist[i].eatmutex));
	return (0);
}

void	deadcheck(t_phil *philone)
{
	struct timeval	present;
	unsigned int	gap;
	t_rule			*rule;

	rule = philone->rule;
	gettimeofday(&present, 0);
	pthread_mutex_lock(&(philone->eatmutex));
	gap = timegap(philone->eat, present);
	pthread_mutex_unlock(&(philone->eatmutex));
	if (gap > (rule->time_to_die))
	{
		endmutexchange(rule);
		ph_notice(philone, "is dead");
	}
}

void	endcheck(t_phil *philist)
{
	unsigned int	i;
	unsigned int	end;
	t_rule			*rule;

	rule = philist->rule;
	end = 0;
	while (!(endmutexcheck(rule)))
	{
		i = 0;
		while (!(endmutexcheck(rule)) && i < rule->num_of_phil)
		{
			if (end == rule->num_of_phil)
				endmutexchange(rule);
			else if (rule->must_eat)
			{
				if (eatnumcheck(philist, i))
					end++;
				else
					end = 0;
			}
			deadcheck(&(philist[i]));
			i++;
		}
	}
}

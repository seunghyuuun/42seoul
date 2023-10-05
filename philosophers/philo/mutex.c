/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:14:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/30 10:59:55 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	endmutexcheck(t_rule *rule)
{
	unsigned int	result;

	pthread_mutex_lock(&(rule->endmutex));
	result = rule->end;
	pthread_mutex_unlock(&(rule->endmutex));
	return (result);
}

void	endmutexchange(t_rule *rule)
{
	pthread_mutex_lock(&(rule->endmutex));
	rule->end = 1;
	pthread_mutex_unlock(&(rule->endmutex));
}

void	forkmutexdestroy(t_rule *rule, unsigned int end)
{
	unsigned int	i;
	t_fork			*forks;

	i = 0;
	forks = rule->forks;
	while (i < end)
	{
		pthread_mutex_destroy(&((forks[i]).fkmtx));
		i++;
	}
}

int	forkmutexset(t_rule *rule)
{
	unsigned int	i;
	unsigned int	max;
	t_fork			*forks;

	i = 0;
	forks = rule->forks;
	max = rule->num_of_phil;
	while (i < max)
	{
		if (pthread_mutex_init(&((forks[i]).fkmtx), 0) == -1)
		{
			forkmutexdestroy(rule, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

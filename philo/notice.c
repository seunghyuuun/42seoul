/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:33:22 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 16:42:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	microphone(t_phil *philone)
{
	struct timeval	time;
	unsigned int	present;
	unsigned int	dead;
	unsigned int	i;

	gettimeofday(&time, 0);
	dead = timegap(philone->eat, time);
	present = timegap(philone->rules->start, time);
	i = philone->index;
	if (dead >= philone->rules->time_to_die)
	{
		printf("%u %u died\n", present, i + 1);
		return (0);
	}
	if (philone->renewal)
	{
		philone->renewal = 0;
		if (philone->status == EAT)
		{
			printf("%u %u has taken a fork\n", present, i + 1);
			printf("%u %u is eating\n", present, i + 1);
		}
		else if (philone->status == SLEEP)
			printf("%u %u is sleeping\n", present, i + 1);
		else if (philone->status == THINK)
			printf("%u %u is thinking\n", present, i + 1);
	}
	return (1);
}

void	*ph_notice(void *phil)
{
	t_phil			*philo;
	unsigned int	size;
	int				flag;
	unsigned int	i;

	philo = (t_phil *)phil;
	size = philo->rules->num_of_phil;
	flag = 1;
	i = 0;
	while (flag)
	{
		flag = microphone(&(philo[i]));
		i = indexset(i + 1, size);
	}
	return (0);
}

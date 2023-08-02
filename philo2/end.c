/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:40:13 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/02 15:02:51 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errorend(t_rule *rule)
{
	free(rule->forks);
	write(2, "Error\n", 6);
	exit (-1);
}

void	successend(t_rule *rule)
{
	free(rule->forks);
	exit(0);
}

void	deadcheck(t_phil *philone)
{
	struct timeval	present;
	unsigned int	gap;
	t_rule			*rule;

	rule = philone->rule;
	gettimeofday(&present, 0);
	gap = timegap(philone->eat, present);
	if (gap > rule->time_to_die)
	{
		ph_notice(philone, present, "is dead");
		rule->end = 1;
	}
}

void	endcheck(t_phil *philist)
{
	unsigned int	i;
	unsigned int	end;
	t_rule			*rule;

	rule = philist->rule;
	end = 0;
	while (!(rule->end))
	{
		i = 0;
		while (!(rule->end) && i < rule->num_of_phil)
		{
			if (end == rule->num_of_phil)
				rule->end = 1;
			else if (rule->must_eat && (philist[i]).eatnum >= rule->must_eat)
				end++;
			else
				end = 0;
			deadcheck(&(philist[i]));
			i++;
		}
	}
}

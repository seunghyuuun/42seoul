/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:37 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/28 12:44:50 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timegap(struct timeval start, struct timeval present)
{
	unsigned long long	sec;
	unsigned int		mil;

	sec = present.tv_sec - start.tv_sec;
	mil = (unsigned int)sec * 1000000 + present.tv_usec - start.tv_usec;
	return (mil);
}

void	*psychopomp(void *ph)
{
	t_phil	**philist;
	unsigned int	i;
	unsigned int	end;
	struct timeval	present;
	t_rule			*rule;

	philist = (t_phil **)ph;
	rule = (*philist)->rule;
	end = 0;
	while (1)
	{
		i = 0;
		while (i < rule->num_of_phil)
		{
			if (end == rule->num_of_phil)
			{
				rule->end = 1;
				return (0);
			}
			gettimeofday(&present, 0);
			if (timegap(((*philist)[i]).eat, present) >= rule->time_to_die)
			{
				ph_notice((&((*philist)[i])), "is dead");
				rule->dead = 1;
				return (0);
			}
			if (rule->must_eat && ((*philist)[i]).eatnum >= rule->must_eat)
				end++;
			else
				end = 0;
			i++;
		}
	}
	return (0);
}

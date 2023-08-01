/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:40:13 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/01 19:19:08 by seunghy2         ###   ########.fr       */
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

void	*endcheck(void *ph)
{
	t_phil			**philist;
	unsigned int	i;
	unsigned int	end;
	t_rule			*rule;

	philist = (t_phil **)ph;
	rule = (*philist)->rule;
	end = 0;
	while (!(rule->end))
	{
		i = 0;
		while (!(rule->end) && i < rule->num_of_phil)
		{
			if (end == rule->num_of_phil)
				rule->end = 1;
			else if (rule->must_eat && ((*philist)[i]).eatnum >= rule->must_eat)
				end++;
			else
				end = 0;
			i++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:28:12 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/08 15:04:13 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned int	atou(char *str)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			erroend();
		else
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ruleinit(t_rule *rule, int argc, char **argv)
{
	memset((void *)rule, 0, sizeof(t_rule));
	rule->time_to_die = atou(argv[2]);
	rule->time_to_eat = atou(argv[3]);
	rule->time_to_sleep = atou(argv[4]);
	if (argc == 6)
	{
		rule->must_eat = atou(argv[5]);
		if (!rule->must_eat)
			rule->end = 1;
	}
	rule->num_of_phil = atou(argv[1]);
	gettimeofday(&(rule->start), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:31:20 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 17:01:49 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	atou(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			errorend();
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	initset(t_phil **plist, t_rule *rules, int argc, char **argv)
{
	unsigned int	i;

	pthread_mutex_init(&(rules->mutex), 0);
	rules->time_to_die = atou(argv[2]);
	rules->time_to_eat = atou(argv[3]);
	rules->time_to_sleep = atou(argv[4]);
	if (argc == 5)
		rules->must_eat = 0;
	else
	{
		rules->must_eat = (unsigned int *)malloc(sizeof(unsigned int));
		if (!rules->must_eat)
			errorend();
		*(rules->must_eat) = atou(argv[5]);
	}
	rules->num_of_phil = atou(argv[1]);
	*plist = (t_phil *)malloc(sizeof(t_phil) * rules->num_of_phil);
	if (!(*plist))
		errorend();
	rules->forks = (int *)malloc(sizeof(int) * rules->num_of_phil);
	if (!rules->forks)
		errorend();
	i = 0;
	while (i < rules->num_of_phil)
	{
		(&((*plist)[i]))->rules = rules;
		(&((*plist)[i]))->index = i;
		(&((*plist)[i]))->renewal = 0;
		(&((*plist)[i]))->status = 0;
		(&((*plist)[i]))->eat = rules->start;
		(rules->forks)[i] = 1;
		i++;
	}
}

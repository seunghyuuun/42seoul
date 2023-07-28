/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:25 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/28 17:04:18 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	atou(t_rule *rule, char *str)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			errorend(rule);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ruleinit(t_rule *rule, int argc, char **argv)
{
	rule->time_to_die = atou(rule, argv[2]);
	rule->time_to_eat = atou(rule, argv[3]);
	rule->time_to_sleep = atou(rule, argv[4]);
	if (argc == 6)
	{
		rule->must_eat = atou(rule, argv[5]);
		if (!rule->must_eat)
			successend(rule);
	}
	rule->num_of_phil = atou(rule, argv[1]);
	rule->forks = malloc(sizeof(unsigned int) * rule->num_of_phil);
	if (!rule->forks)
		errorend(rule);
	memset((void *)(rule->forks), 0, sizeof(unsigned int) * (rule->num_of_phil));
	if (pthread_mutex_init(&(rule->pick_fork), 0) == -1)
		errorend(rule);
	if (pthread_mutex_init(&(rule->notice), 0) == -1)
		errorend(rule);
	gettimeofday(&(rule->start), 0);
}

void	philinit(t_phil **philist, t_rule *rule)
{
	unsigned int	i;

	*philist = (t_phil *)malloc(sizeof(t_phil) * rule->num_of_phil);
	if (!(*philist))
		errorend(rule);
	i = 0;
	while (i < rule->num_of_phil)
	{
		((*philist)[i]).index = i;
		((*philist)[i]).eat = rule->start;
		((*philist)[i]).rule = rule;
		((*philist)[i]).eatnum = 0;
		i++;
	}
}

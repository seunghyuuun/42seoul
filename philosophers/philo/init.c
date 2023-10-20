/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:25 by seunghy2          #+#    #+#             */
/*   Updated: 2023/10/19 17:11:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	atou(char *str, int *error)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			*error = -1;
		else
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ruleinit(t_rule *rule, int argc, char **argv)
{
	int	error;

	error = 0;
	memset((void *)rule, 0, sizeof(t_rule));
	rule->time_to_die = atou(argv[2], &error);
	rule->time_to_eat = atou(argv[3], &error);
	rule->time_to_sleep = atou(argv[4], &error);
	if (argc == 6)
	{
		rule->must_eat = atou(argv[5], &error);
		if (!rule->must_eat)
			rule->end = 1;
	}
	rule->num_of_phil = atou(argv[1], &error);
	if (!(rule->num_of_phil))
		error = -1;
	if (error)
		return (-1);
	rule->forks = malloc(sizeof(t_fork) * rule->num_of_phil);
	if (!(rule->forks))
		return (-1);
	memset((void *)(rule->forks), 0, \
			sizeof(t_fork) * (rule->num_of_phil));
	return (0);
}

int	philinit(t_phil **philist, t_rule *rule)
{
	unsigned int	i;

	*philist = (t_phil *)malloc(sizeof(t_phil) * rule->num_of_phil);
	if (!(*philist))
		return (allfree(rule, 3, 0, 0));
	i = 0;
	while (i < rule->num_of_phil)
	{
		memset((void *)(&((*philist)[i])), 0, sizeof(t_phil));
		((*philist)[i]).index = i;
		((*philist)[i]).rule = rule;
		((*philist)[i]).eatnum = 0;
		if (pthread_mutex_init(&(((*philist)[i]).eatmutex), 0) == -1)
			return (allfree(rule, 3, *philist, i));
		i++;
	}
	return (0);
}

int	ph_initial(int argc, char **argv, t_rule *rule, t_phil **list)
{
	if (ruleinit(rule, argc, argv))
		return (-1);
	if (forkmutexset(rule) == -1)
		return (allfree(rule, 0, 0, 0));
	if (pthread_mutex_init(&(rule->notice), 0) == -1)
		return (allfree(rule, 1, 0, 0));
	if (pthread_mutex_init(&(rule->endmutex), 0) == -1)
		return (allfree(rule, 2, 0, 0));
	if (philinit(list, rule))
		return (-1);
	return (0);
}	

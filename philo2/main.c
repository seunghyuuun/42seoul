/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:34:54 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/24 19:59:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule			rule;
	t_phil			*philist;
	unsigned int	i;

	if (argc != 5 && argc != 6)
		return (-1);
	memset((void *)(&rule), 0, sizeof(t_rule));
	ruleinit(&rule, argc, argv);
	philinit(&philist, &rule);
	pthread_mutex_init(&(rule.notice), 0);
	i = 0;
	while (i < rule.num_of_phil)
	{
		if (pthread_create(&(philist[i].thread), 0, &ph_schedul, &(philist[i])))
		{
			free(philist);
			errorend(&rule);
		}
		i++;
	}
	while (--i)
		pthread_join(philist[i].thread, 0);
	pthread_join(philist[0].thread, 0);
	return (0);
}

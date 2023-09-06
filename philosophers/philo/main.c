/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:34:54 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 13:56:58 by seunghy2         ###   ########.fr       */
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
	if (ph_initial(argc, argv, &rule, &philist))
		return (-1);
	i = 0;
	while (i < rule.num_of_phil)
	{
		if (pthread_create(&(philist[i].thread), 0, &ph_schedul, &(philist[i])))
		{
			endmutexchange(&rule);
			break ;
		}
		i++;
	}
	endcheck(philist);
	while (--i)
		pthread_join(philist[i].thread, 0);
	pthread_join(philist[0].thread, 0);
	allfree(&rule, 3, philist, rule.num_of_phil);
	return (0);
}

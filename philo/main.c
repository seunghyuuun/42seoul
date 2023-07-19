/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:39:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 17:01:43 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule			rules;
	t_phil			*plist;
	pthread_t		notice;
	unsigned int	i;

	if (argc != 5 && argc != 6)
		return (-1);
	gettimeofday(&(rules.start), 0);
	initset(&plist, &rules, argc, argv);
	i = 0;
	pthread_create(&notice, 0, ph_notice, plist);
	while (i < rules.num_of_phil)
	{
		pthread_create(&(plist[i].thread), 0, ph_schedul, &(plist[i]));
		i++;
	}
	while (i < rules.num_of_phil)
	{
		pthread_join(plist[i].thread, 0);
		i++;
	}
	pthread_join(notice, 0);
	return (0);
}

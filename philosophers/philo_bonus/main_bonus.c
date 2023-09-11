/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:11:09 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 17:19:07 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_rule	rule;
	unsigned int	i;
	unsigned int	parentflag;

	if (argc != 5 && argc != 6)
		return (-1);
	if (ruleinit(&rule, argc, argv) == -1)
		return (-1);
	i = 0;
	parentflag = 1;
	while (parentflag && i < rule.num_of_phil)
	{
		(rule.phils)[i] = fork();
		if (!((rule.phils)[i]))
			parentflag = 0;
		i++;
	}
	return (0);
}

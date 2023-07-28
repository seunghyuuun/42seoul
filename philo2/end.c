/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:40:13 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/28 17:04:40 by seunghy2         ###   ########.fr       */
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

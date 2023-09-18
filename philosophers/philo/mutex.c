/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:14:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/18 18:34:22 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	endmutexcheck(t_rule *rule)
{
	unsigned int	result;

	pthread_mutex_lock(&(rule->endmutex));
	result = rule->end;
	pthread_mutex_unlock(&(rule->endmutex));
	return (result);
}

void	endmutexchange(t_rule *rule)
{
	pthread_mutex_lock(&(rule->endmutex));
	rule->end = 1;
	pthread_mutex_unlock(&(rule->endmutex));
}

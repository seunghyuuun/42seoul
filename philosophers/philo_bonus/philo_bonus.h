/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:11:50 by seunghy2          #+#    #+#             */
/*   Updated: 2023/09/06 17:09:32 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>

# define SFORK "/philobonusfork"
# define SNOTICE "/philobonusnotice"
# define SUCCESS 0
# define EATDONE 1
# define DEAD 2

typedef struct s_rule
{
	unsigned int	num_of_phil;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	must_eat;
	unsigned int	end;
	pid_t			*phils;
	struct timeval	start;
	sem_t			*forks;
	sem_t			*notice;
}	t_rule;

#endif

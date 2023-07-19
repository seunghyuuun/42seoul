/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/19 16:43:58 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct s_rule
{
	unsigned int	num_of_phil;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	*must_eat;
	pthread_mutex_t	mutex;
	int				*forks;
	struct timeval	start;
}	t_rule;

typedef struct s_phil
{
	pthread_t		thread;
	t_rule			*rules;
	unsigned int	index;
	int				renewal;
	int				status;
	struct timeval	eat;
	struct timeval	sleep;
}	t_phil;

void			initset(t_phil **plist, t_rule *rules, int argc, char **argv);
void			*ph_schedul(void *phil);
void			*ph_notice(void *phil);
void			errorend(void);
unsigned int	indexset(unsigned int i, unsigned int num_of_phil);
unsigned int	timegap(struct timeval start, struct timeval end);
unsigned int	sch_timegap(struct timeval start, struct timeval end);

#endif

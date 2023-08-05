/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:51 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/05 17:47:07 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_rule
{
	unsigned int	num_of_phil;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	must_eat;
	unsigned int	end;
	unsigned int	*forks;
	pthread_mutex_t	pick_fork;
	pthread_mutex_t	notice;
	struct timeval	start;
}	t_rule;

typedef struct s_phil
{
	pthread_t		thread;
	unsigned int	index;
	unsigned int	eatnum;
	struct timeval	eat;
	t_rule			*rule;
}	t_phil;

int				ph_initial(int argc, char **argv, t_rule *rule, t_phil **list);
void			*ph_schedul(void *phil);
void			ph_notice(t_phil *philone, struct timeval present, char *str);
void			endcheck(t_phil *philist);
unsigned int	timegap(struct timeval start, struct timeval present);
void			napping(unsigned int sleep, struct timeval start);
int				allfree(t_rule *rule, int mutexinit, t_phil *philist);

#endif

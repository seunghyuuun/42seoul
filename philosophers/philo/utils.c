/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:13:41 by seunghy2          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:10 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timegap(struct timeval start, struct timeval present)
{
	long				sec;
	unsigned int		mic;

	if (start.tv_sec > present.tv_sec)
		return (0);
	sec = present.tv_sec - start.tv_sec;
	mic = ((unsigned int)sec) * 1000;
	if (!mic && start.tv_usec >= present.tv_usec)
		return (0);
	mic += (present.tv_usec - start.tv_usec) / 1000;
	return (mic);
}

void	napping(unsigned int sleep, struct timeval start, t_phil *philone)
{
	unsigned int	gap;
	unsigned int	tmp;
	struct timeval	present;

	gap = 0;
	while (!(endmutexcheck(philone->rule)) && gap < sleep)
	{
		tmp = (sleep - gap) / 3;
		if (tmp > 1)
			usleep(tmp * 1000);
		else
			usleep(300);
		gettimeofday(&present, 0);
		gap = timegap(start, present);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		c;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		c = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (c)
			return (c);
		i++;
	}
	return (0);
}

void	ph_notice(t_phil *philone, char *str)
{
	unsigned int	gap;
	struct timeval	start;
	struct timeval	present;

	if (ft_strcmp(str, "is dead") && endmutexcheck(philone->rule))
		return ;
	start = philone->rule->start;
	pthread_mutex_lock(&(philone->rule->notice));
	if (endmutexcheck(philone->rule) && ft_strcmp(str, "is dead"))
	{
		pthread_mutex_unlock(&(philone->rule->notice));
		return ;
	}
	gettimeofday(&present, 0);
	gap = timegap(start, present);
	if (!(ft_strcmp(str, "is dead")) || !(endmutexcheck(philone->rule)))
		printf("%u %u %s\n", gap, (philone->index) + 1, str);
	pthread_mutex_unlock(&(philone->rule->notice));
}

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_rule
{
    unsigned int num_of_phil;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int *must_eat;
    int *forks;
} t_rule;

typedef struct s_phil
{
    pthread_t *thread;
    t_rule *rules;
    unsigned int index;
    int renewal;
} t_phil;

void initset(t_phil **plist, t_rule *rules, int argc, char **argv);
void errorend(void);

#endif
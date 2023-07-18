#include "philo.h"

void errorend(void)
{
    write(2, "Error\n", 6);
    exit (-1);
}
#include "push_swap.h"

int argcheck(char *str)
{
    int i;
    int digit;

    i = 0;
    digit = 0;
    while (str[i])
    {
        if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
            i++;
        else if (ft_isdigit(str[i]))
        {
            digit++;
            i++;
        }
        else if (str[i] == ' ')
            i++;
        else
            return (-1);
    }
    if (!digit)
        return (-1);
    return (0);
}
#include "ft_printf.h"

char    *ch_char(char *unchange, int c)
{
    char    *change;
    int     i;
    t_flag  flag;
    size_t  size;

    flagstore(&flag, unchange);
    if (flag.xx > 1)
        size = (size_t)flag.xx;
    else
        size = 1;
    change = (char *)malloc(sizeof(char) * (size + 1));
    if (!change)
        return (0);
    change[size] = '\0';
    if (!(flag.minus) && flag.zero)
        ft_memset((void *)change, '0', size);
    else
        ft_memset((void *)change, ' ', size);
    if (flag.minus)
        change[0] = c;
    else
        change[size - 1] = c;
    return (change);
}
#include "ft_printf.h"

char    *ch_str(char *unchange, char *str)
{
    char    *change;
    int     i;
    t_flag  flag;
    size_t  xsize;
    size_t  ysize;

    flagstore(&flag, unchange);
    ysize = ft_strlen(str);
    if (flag.yy != -1 && ysize > (size_t)flag.yy)
        ysize = (size_t)flag.yy;
    xsize = ysize;
    if (flag.xx != -1 && (size_t)flag.xx > ysize)
        xsize = (size_t)flag.xx;
    change = (char *)malloc(sizeof(char) * (xsize + 1));
    if (!change)
        return (0);
    change[xsize] = '\0';
    ft_memset((void *)change, ' ', xsize);
    if (!(flag.minus) && flag.zero)
        ft_memset((void *)change, '0', xsize);
    if (flag.minus)
        ft_memcpy((void *)change, (void *)str, ysize);
    else
        ft_memcpy((void *)(&(change[xsize - ysize])), (void *)str, ysize);
    return (change);
}
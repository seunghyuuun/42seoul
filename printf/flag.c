#include "ft_printf.h"

int ft_isflag(int c)
{
    if (ft_isdigit(c))
        return (1);
    if (ft_strchr("# +-.", c))
        return (1);
    return (0);
}

void    initialflag(t_flag *flag)
{
    flag->hash = 0;
    flag->space = 0;
    flag->plus = 0;
    flag->minus = 0;
    flag->zero = 0;
    flag->xx = -1;
    flag->yy = -1;
}

int atoijump(char *start, int *jump)
{
    int i;
    int result;

    i = 0;
    if (start[i] == '.')
        i++;
    if (start[i] == ' ' || start[i] == '+' || start[i] == '-')
        return (0);
    result = ft_atoi(&(start[i]));
    while (ft_isdigit(start[i]))
        i++;
    *jump = i;
    return (result);
}

void    flagstore(t_flag *flag, char *unchange)
{
    int i;
    int jump;

    i = 0;
    initialflag(flag);
    while (unchange[i])
    {
        jump = 1;
        if (unchange[i] == '#')
            flag->hash = 1;
        else if (unchange[i] == ' ')
            flag->space = 1;
        else if (unchange[i] == '+')
            flag->plus = 1;
        else if (unchange[i] == '-')
            flag->minus = 1;
        else if (unchange[i] == '0')
            flag->zero = 1;
        else if (ft_isdigit(unchange[i]))
            flag->xx = atoijump(&(unchange[i]), &jump);
        else if (unchange[i] == '.')
            flag->yy = atoijump(&(unchange[i]), &jump);
        i += jump;
    }
}
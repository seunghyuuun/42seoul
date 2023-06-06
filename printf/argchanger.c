#include "ft_printf.h"

char    *optiondup(char *str, char *type)
{
    char    *result;
    int     size;
    int     i;

    size = 1;
    while (str[size] && ft_isflag(str[size]))
        size++;
    if (str[size])
    {
        *type = str[size];
        size++;
    }
    result = (char *)malloc(sizeof(char) * (size));
    if (!result)
        return (0);
    i = 0;
    while (i + 1 < size)
    {
        result[i] = str[i + 1];
        i++;
    }
    result[i] = '\0';
    return (result);
}

char	*argchanger(va_list arg, char **str)
{
    char    *change;
    char    *unchange;
    char    type;

    type = 0;
    unchange = optiondup(*str, &type);
    if (!unchange)
        return (0);
    *str += ft_strlen(unchange) + 1;
    if (type == 'c')
        change = ch_char(unchange, va_arg(arg, int));
    else if (type == 's')
        change = ch_str(unchange, va_arg(arg, char*));
    return (change);
}

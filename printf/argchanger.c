#include "ft_printf.h"

char    *optiondup(char *str, char *type)
{
    char    *result;
    int     size;
    int     i;

    size = 1;
    while (str[size] && !(ft_isalpha(str[size]) || str[size] == '%'))
        size++;
    if (str[size])
    {
        *type = str[size];
        size++;
    }
    result = (char *)malloc(sizeof(char) * (size + 1));
    if (!result)
        return (0);
    i = 0;
    while (i < size)
    {
        result[i] = str[i];
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
    *str += ft_strlen(unchange);
}

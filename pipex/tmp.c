#include "pipex.h"

char    *nonexitpath(void)
{
    char    *result;
    char    *temp;
    int     i;

    result = ft_strdup("./A");
    i = 2;
    while (result && !access(result, F_OK))
    {
        result[i]++;
        if (result[i] == 'z')
        {
            while(result[i] == 'z')
                result[i++] = 'A';
            if (!result[i])
            {
                temp = result;
                result = ft_strjoin(temp, "A");
                free(temp);
            }
            else
                result[i]++;
            i = 2;
        }
    }
    return (result);
}
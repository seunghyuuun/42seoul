#include "get_next_line.h"

void    ft_free(char *str)
{
    if (str)
        free (str);
}

int    onelinetaker(char  **result, char **store, int ready)
{
    char    *storebaby;
    char    *result;
    char    *temp;


    if (!ready)
        *result = ft_strdup("");
    if (!(*store))
        return (0);
    storebaby = ft_strchr(*store, '\n');
    if (!storebaby)
    {
        temp = ft_strjoin(*result, *store);
        ft_free(*result);
        *result = temp;
        ft_free(*store);
        *store = 0;
        return (0);
    }
    else
    {
        *storebaby = '\0';
        temp = ft_strjoin(*result, *store);
        ft_free(*result);
        *result = temp;
        temp = ft_strdup(storebaby + 1);
        ft_free(*store);
        *store = temp;
        return (1);
    }
}

char    *get_next_line(int fd)
{
    static char *store;
    char    *result;
    char    *buff;
    char    *temp;
    int     letters;

    if (onelinetaker(&result, &store, 0))
        return (result);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return 0;
    letters = read(fd, buff, BUFFER_SIZE);
    while (letters)
    {
        if (letters < 0)
            return 0;
        buff[letters] = '\0';
        if (!store)
            store = ft_strdup("");
        temp = ft_strjoin(store, buff);
        ft_free(store);
        store = temp;
        if (onelinetaker(&result, &store, 1))
            return (result);
        letters = read(fd, buff, BUFFER_SIZE);
    }
}
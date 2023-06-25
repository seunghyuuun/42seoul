#include "push_swap.h"

int samecheck(t_stack *abstack, int n)
{
    t_idata *node;

    node = abstack->atop;
    while (node)
    {
        if (node->data == n)
            return (1);
        node = node->next;
    }
    return (0);
}

t_idata *nodemaker(t_stack *abstack, char *strdata)
{
    t_idata *result;
    int data;

    data = ft_atoi(strdata);
    if (samecheck(abstack, data))
        return (0);
    result = (t_idata *)malloc(sizeof(t_idata));
    if (!result)
        return (result);
    result->data = data;
    result->next = 0;
    result->back = 0;
    return (result);
}

int piececheck(char *str)
{
    size_t i;
    size_t size;
    char *temp;

    i = 0;
    size = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    temp = &str[i];
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        size++;
        i++;
    }
    if (size > 10)
        return (0);
    else if (size == 10 && str[0] == '-' && ft_strncmp(temp, "2147483648", size) > 0)
        return (0);
    else if (size == 10 && str[0] != '-' && ft_strncmp(temp, "2147483647", size) > 0)
        return (0);
    return (1);
}

int listing(t_stack *abstack, char *str)
{
    char **pieces;
    int i;
    t_idata *node;
    int result;

    result = 0;
    pieces = ft_split(str, ' ');
    if (!pieces)
        return (result);
    i = 0;
    while (pieces[i])
    {
        if(!piececheck(pieces[i]))
            break ;
        node = nodemaker(abstack, pieces[i]);
        if (!node)
            break ;
        stackbottom(abstack, node, 'a');
        i++;
    }
    if (i && !pieces[i])
        result = 1;
    twodfree(pieces);
    return (result);
}

void initialset(t_stack *abstack, char **argv, int argc)
{
    int i;

    i = 1;
    abstack->atop = 0;
    abstack->btop = 0;
    abstack->abottom = 0;
    abstack->bbottom = 0;
    while (i < argc)
    {
        if (!(listing(abstack, argv[i])))
        {
            allstackfree(abstack);
            ft_printf("Error\n");
            exit (-1);
        }
        i++;
    }
}
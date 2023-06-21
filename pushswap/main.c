#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_stack *abstack;

    i = 1;
    while (i < argc)
    {
        if (argcheck(argv[i]))
            ft_printf("Error\n");
        i++;
    }
}
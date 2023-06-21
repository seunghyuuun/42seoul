#include "push_swap.h"

void ps_swap(t_stack *abstack, int c)
{
    size_t size;
    t_idata *second;

    if (c == 'a' || c == 'a' + 'b')
    {
        size = stacksize(abstack->atop);
        if (size > 1)
        {
            second = abstack->atop->next;
            stackout(abstack, second, 'a');
            stacktop(abstack, second, 'a');
        }
    }
    if (c == 'b' || c == 'a' + 'b')
    {
        size = stacksize(abstack->btop);
        if (size > 1)
        {
            second = abstack->atop->next;
            stackout(abstack, second, 'b');
            stacktop(abstack, second, 'b');
        }
    }
}

void ps_push(t_stack *abstack, int c)
{
    size_t size;
    t_idata *node;

    if (c == 'a')
    {
        size = stacksize(abstack->btop);
        if (size > 0)
        {
            node = abstack->btop;
            stackout(abstack, node, 'b');
            stacktop(abstack, node, 'a');
        }
    }
    else if (c == 'b')
    {
        size = stacksize(abstack->atop);
        if (size > 0)
        {
            node = abstack->atop;
            stackout(abstack, node, 'a');
            stacktop(abstack, node, 'b');
        }
    }
}

void ps_rotate(t_stack *abstack, int c)

void ps_revrotate(t_stack *abstack, int c)

void comcall(void (*ps)(t_stack*, int), t_stack *abstack, int c)

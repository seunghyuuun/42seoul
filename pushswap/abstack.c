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
{
    size_t size;
    t_idata *first;

    if (c == 'a' || c == 'a' + 'b')
    {
        size = stacksize(abstack->atop);
        if (size > 1)
        {
            first = abstack->atop;
            stackout(abstack, first, 'a');
            stackbottom(abstack, first, 'a');
        }
    }
    if (c == 'b' || c == 'a' + 'b')
    {
        size = stacksize(abstack->btop);
        if (size > 1)
        {
            first = abstack->btop;
            stackout(abstack, first, 'b');
            stackbottom(abstack, first, 'b');
        }
    }
}

void ps_revrotate(t_stack *abstack, int c)
{
    size_t size;
    t_idata *last;

    if (c == 'a' || c == 'a' + 'b')
    {
        size = stacksize(abstack->atop);
        if (size > 1)
        {
            last = abstack->abottom;
            stackout(abstack, last, 'a');
            stacktop(abstack, last, 'a');
        }
    }
    if (c == 'b' || c == 'a' + 'b')
    {
        size = stacksize(abstack->btop);
        if (size > 1)
        {
            last = abstack->bbottom;
            stackout(abstack, last, 'b');
            stacktop(abstack, last, 'b');
        }
    }
}

void comcall(void (*ps)(t_stack*, int), t_stack *abstack, int c)
{
    int first;
    int second;

    first = 0;
    second = 0;
    if (ps == ps_swap)
        first = 's';
    else if (ps == ps_push)
        first = 'p';
    else if (ps == ps_rotate)
        first = 'r';
    else if (ps == ps_revrotate)
    {
        first = 'r';
        ft_printf("%c", first);
    }
    if (c == 'a' + 'b')
        second = first;
    else if (c == 'a' || c == 'b')
        second = c;
    ft_printf("%c%c\n", first, second);
    ps(abstack, c);
}

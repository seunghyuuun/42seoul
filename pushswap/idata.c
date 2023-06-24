#include "push_swap.h"

size_t stacksize(t_idata *top)
{
    size_t result;
    t_idata *temp;

    temp = top;
    result = 0;
    while (temp)
    {
        temp = temp->next;
        result++;
    }
    return (result);
}

void stackout(t_stack *abstack, t_idata *node, int c)
{
    t_idata *next;
    t_idata *back;

    next = node->next;
    back = node->back;
    if (next)
        next->back = back;
    else
    {
        if (c == 'a')
            abstack->abottom = back;
        else if (c == 'b')
            abstack->bbottom = back;
    }
    if (back)
        back->next = next;
    else
    {
        if (c == 'a')
            abstack->atop = next;
        else if (c == 'b')
            abstack->btop = next;
    }
    node->next = 0;
    node->back = 0;
}

void stacktop(t_stack *abstack, t_idata *node, int c)
{
    t_idata *second;

    if (c == 'a')
    {
        second = abstack->atop;
        if (second)
        {
            second->back = node;
            node->next = second;
        }
        else
            abstack->abottom = node;
        abstack->atop = node;
    }
    else if (c == 'b')
    {
        second = abstack->btop;
        if (second)
        {
            second->back = node;
            node->next = second;
        }
        else
            abstack->bbottom = node;
        abstack->btop = node;
    }
}

void stackbottom(t_stack *abstack, t_idata *node, int c)
{
    t_idata *second;

    if (c == 'a')
    {
        second = abstack->abottom;
        if (second)
        {
            second->next = node;
            node->back = second;
        }
        else
            abstack->atop = node;
        abstack->abottom = node;
    }
    else if (c == 'b')
    {
        second = abstack->bbottom;
        if (second)
        {
            second->next = node;
            node->back = second;
        }
        else
            abstack->btop = node;
        abstack->bbottom = node;
    }
}
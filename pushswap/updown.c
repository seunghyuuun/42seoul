#include "push_swap.h"

void updown(t_idata *start, size_t arr[3], int next)
{
    t_idata *node;

    arr[1] = 1;
    arr[2] = 0;
    if (!start)
    {
        arr[1] = 0;
        node = 0;
    }
    else if (next)
        node = start->next;
    else
        node = start->back;
    if (!node)
        arr[0] = 0;
    else if (start->data > node->data)
        arr[0] = (size_t)'-';
    else
        arr[0] = (size_t)'+';
}

size_t stepdown(t_idata *start, int next)
{
    t_idata *temp;
    size_t result;

    result = 0;
    temp = start;
    if (next)
    {
        while (temp->next && temp->data > temp->next->data)
        {
            temp = temp->next;
            result++;
        }
    }
    else
    {
        while (temp->back && temp->data > temp->back->data)
        {
            temp = temp->back;
            result++;
        }
    }
    return (result);
}

size_t stepup(t_idata *start, int next)
{
    t_idata *temp;
    size_t result;

    result = 0;
    temp = start;
    if (next)
    {
        while (temp->next && temp->data < temp->next->data)
        {
            temp = temp->next;
            result++;
        }
    }
    else
    {
        while (temp->back && temp->data < temp->back->data)
        {
            temp = temp->back;
            result++;
        }
    }
    return (result + 1);
}

void counting(t_idata *start, size_t arr[3], int next)
{
    size_t count;
    t_idata *node;

    node = start;
    if (!arr[0])
        return ;
    else if (arr[0] == (size_t)'+')
        arr[1] = stepup(start, next);
    else
        arr[1] = stepdown(start, next);
    count = arr[1];
    while (--count)
    {
        if (next)
            node = node->next;
        else
            node = node->back;
    }
    if (arr[0] == (size_t)'+')
        arr[2] = stepdown(node, next);
    else
        arr[2] = stepup(node, next);
}

void udcheck(t_stack *abstack, t_updown *udinfo)
{
    updown(abstack->atop, udinfo->a_top, 1);
    updown(abstack->abottom, udinfo->a_bottom, 0);
    updown(abstack->btop, udinfo->b_top, 1);
    updown(abstack->bbottom, udinfo->b_bottom, 0);
    counting(abstack->atop, udinfo->a_top, 1);
    counting(abstack->abottom, udinfo->a_bottom, 0);
    counting(abstack->btop, udinfo->b_top, 1);
    counting(abstack->bbottom, udinfo->b_bottom, 0);
}
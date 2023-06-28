#include "push_swap.h"

void restbig(t_stack *abstack, size_t size)
{
    int pivot[2];

    pivotmaker(abstack->atop, size, pivot);
}
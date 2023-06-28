#include "push_swap.h"

void pivotmaker(t_idata *top, size_t size, int pivot[2])
{
    size_t i;
    t_idata *temp;
    int *frame;
    size_t third;

    third = size / 3;
    if (size % 3 == 2)
        third = (size + 1) / 3;
    frame = (int *)malloc(sizeof(int) * (third));
    i = third;
    temp = top;
    framesetting(&temp, frame, third);
    while (i < size)
    {
        bestchanger(frame, temp->data);
        temp = temp->next;
        i++;
    }
    pivot[0] = bestfinder(frame);
    i = third;
    temp = top;
    framesetting(&temp, frame, third);
    while (i < size)
    {
        worstchanger(frame, temp->data);
        temp = temp->next;
        i++;
    }
    pivot[1] = worstfinder(frame);
}
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack abstack;

    initialset(&abstack, argv, argc);
    restbig(&abstack, stacksize(abstack.atop));
}
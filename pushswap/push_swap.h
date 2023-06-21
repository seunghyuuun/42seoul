#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_idata
{
    int data;
    struct s_idata *next;
    struct s_idata *back;
} t_idata;

typedef struct s_stack
{
    t_idata *atop;
    t_idata *abottom;
    t_idata *btop;
    t_idata *bbottom;
} t_stack;

#endif
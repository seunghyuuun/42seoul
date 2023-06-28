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

void comcall(void (*ps)(t_stack*, int), t_stack *abstack, int c);
void ps_swap(t_stack *abstack, int c);
void ps_push(t_stack *abstack, int c);
void ps_rotate(t_stack *abstack, int c);
void ps_revrotate(t_stack *abstack, int c);
size_t stacksize(t_idata *top);
void stackout(t_stack *abstack, t_idata *node, int c);
void stacktop(t_stack *abstack, t_idata *node, int c);
void stackbottom(t_stack *abstack, t_idata *node, int c);

void restbig(t_stack *abstack, size_t size);

void allstackfree(t_stack *abstack);
void twodfree(char **strs);

int	ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
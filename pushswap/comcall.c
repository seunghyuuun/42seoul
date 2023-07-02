#include "push_swap.h"

void	comcall(void (*ps)(t_stack*, int), t_stack *abstack, int c)
{
	int	first;
	int	second;

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
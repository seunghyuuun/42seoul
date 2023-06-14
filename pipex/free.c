//#include "pipe.h"
#include <stdlib.h>

void	twodfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	threedfree(char ***s, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		twodfree(s[i]);
		i++;
	}
	free(s);
}

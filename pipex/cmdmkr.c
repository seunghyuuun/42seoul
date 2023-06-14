//#include "pipe.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	threedfree(char ***s, int index);

char	***cmdmkr(int argc, char **argv)
{
	char	***result;
	int		i;

	result = (char ***)malloc(sizeof(char **) * (argc - 3 + 1));
	if (!result)
		return (0);
	result[argc - 3] = (char **)0;
	i = 0;
	while (i < argc - 3)
	{
		result[i] = ft_split(argv[i + 2], ' ');
		if (!result[i])
		{
			threedfree(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}

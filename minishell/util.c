#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		c;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		c = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (c)
			return (c);
		i++;
	}
	return (0);
}

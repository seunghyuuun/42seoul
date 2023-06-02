#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

int	main(void)
{
	char	*test = "Hello world!";

	printf("%zu : %s\n", ft_strlen(test), test);

	char	**split = ft_split("Hello %d World %%%%f%d!", '%');
	int	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	return (0);
}

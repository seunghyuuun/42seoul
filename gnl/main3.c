#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*test;

	test = get_next_line(0);
	while (test)
	{
		printf("%s", test);
		free (test);
		test = get_next_line(0);
	}
	/*printf("%s", test);*/
	return (0);
}

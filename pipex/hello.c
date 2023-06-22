#include <stdio.h>

int	main(int argc, char **argv)
{
	argv = 0;
	if (argc == 1)
		printf("Hello World\n");
	else if (argc == 2)
		printf("Hello World!\n");
	else if (argc == 3)
		printf("Hello World!!\n");
	else if (argc == 4)
		printf("Hello World!!!\n");
	else
		printf("more than 3\n");
	return (0);
}

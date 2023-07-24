#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval start;
	struct timeval test1;
	struct timeval test2;

	int	a = 8;
	printf("%d\n", a);
	memset((void *)(&a), 0, sizeof(int));
	printf("%d\n", a);

	gettimeofday(&start, 0);
	test1 = start;
	test2 = start;
	printf("%ld %u\n", start.tv_sec, start.tv_usec);
	printf("%ld %u\n", test1.tv_sec, test1.tv_usec);
	printf("%ld %u\n", test2.tv_sec, test2.tv_usec);
	return (0);
}

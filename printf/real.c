#include <stdio.h>
#include "ft_printf.h"

int	test(va_list lt)
{
	return (va_arg(lt, int));
}

int	sum2(int a, ...)
{
	int result;
	va_list lt;

	va_start(lt, a);
	result = 0;
	int i = 0;
	while (i < a)
	{
		result += test(lt);
		i++;
	}
	va_end(lt);
	return (result);
}

int	sum1(int a, ...)
{
	int	result;
	va_list lt;

	va_start(lt, a);
	int	i = 0;
	result = 0;
	while (i < a)
	{
		result += va_arg(lt, int);
		i++;
	}
	va_end(lt);
	return (result);
}

int	main(void)
{
	int	a = -11;
	int b = 22222222;
	int c = 11;
	int d = -2147483647;

	printf("% d %0#16x %u\n", a, b, d);
	printf("% d %#016x %i\n", c, b ,d);

	printf("\n");

	char *test = "Hello %d World!";
	printf("%.10s\n", test);
	printf("%10s\n", test);
	printf("%10.8s\n%-10.8s\n", test, test);
	printf("%8.10s\n", test);

	printf("\n");

	printf(" : %d\n", printf("test %-13:b", 23));
	printf(" : %d\n", printf("test %-13:%", 42));
	printf(" : %d\n", printf("test %-13", 42));
	printf(" : %d\n", printf("test %d %b %s", 42, test, "No"));

	printf("\n");

	char *nl = 0;
	printf(" : %d\n", printf("%s", nl));

	printf("\n");

	printf("%d\n", sum1(4, 1, 2, 3, 4));
	printf("%d\n", sum2(4, 1, 2, 3, 4));

	return (0);
}

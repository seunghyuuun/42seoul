#include <stdio.h>
#include "ft_printf.h"

int	w = 0;

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

int	order(void)
{
	return ++w;
}

int	main(void)
{
	int	a = -11;
	int b = 22222222;
	int c = 11;
	int d = -2147483647;

	printf("%#+ d %0#10x %u\n", a, b, d);
	printf("% #+d %#010x %i\n", c, b ,d);

	printf("\n");

//문자열 s와 XX.YY
	char *test = "Hello %d World!";
	printf(".10 : %.10s\n", test);
	printf("10 : %10s\n", test);
	printf("010.8 : %010.8s\n%-10.8s\n", test, test);
	printf("8.10 : %8.10s\n", test);
	printf("%+c\n%+s\n%+p\n", 'c', test, test);

	printf("\n");

	printf(" : %d\n", printf("test %-13:b", 23));
	printf(" : %d\n", printf("test %-13:%", 42));
	printf(" : %d\n", printf("test %-13", 42));
	printf(" : %d\n", printf("test %d %b %s", 42, "No", test));

	printf("\n");

	char *nl = 0;
	printf(" : %d\n", printf("%s", nl));

	printf("\n");

// va_arg를 va_start한 함수 밖에서 사용했을 때 잘 작동하는지
	printf("%d\n", sum1(4, 1, 2, 3, 4));
	printf("%d\n", sum2(4, 1, 2, 3, 4));

	printf("\n");

	int u = 11;
	printf("%u\n", u);

	printf("\n");

	int yy = 1111111;
	printf("%.10d\n", yy);
	printf("%.10x\n", yy);
	printf("#.10X : %#.10X\n", yy);
	printf("+010i : %+010i\n", yy);
	printf("+.10i : %+.10i\n", yy);
	printf("%010c\n", 'c');
	printf("+15.10 : %+15.10i\n", yy);
	printf("+015.10 : %+015.10i\n", yy);
	printf("+15 : %+15i\n", yy);
	printf("+015 : %+015i\n", yy);
	printf("15.+10 : %15.+10i\n", yy);

	printf("\n");

	printf("%d %d", order(), order());

	return (0);
}

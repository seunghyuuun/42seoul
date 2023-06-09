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

// va_arg를 va_start한 함수 밖에서 사용했을 때 잘 작동하는지
	printf("%d\n", sum1(4, 1, 2, 3, 4));
	printf("%d\n", sum2(4, 1, 2, 3, 4));

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

// 앞에부터
	printf("%d %d", order(), order());

	printf("\n");

// c
	printf(": 10c(%d)\n", printf("%10c", 'x'));
	printf(": -10c(%d)\n", printf("%-10c", 'x'));
	printf(": 010c(%d)\n", printf("%010c", 'x'));
	printf(": 10.3c(%d)\n", printf("%10.3c", 'x'));
	printf(": 10.03c(%d)\n", printf("%10.03c", 'x'));
	printf(": 010.3c(%d)\n", printf("%010.3c", 'x'));
	printf(": 10..3c(%d)\n", printf("%10..3c", 'x'));
	printf(": 10.3.c(%d)\n", printf("%10.3.c", 'x'));
	printf(": 10.3.5c(%d)\n", printf("%10.3.5c", 'x'));
	printf(": 10.03.5c(%d)\n", printf("%10.03.5c", 'x'));
	printf(": 10.3>c(%d)\n", printf("%10.3>c", 'x'));
	printf(": 10.3-c(%d)\n", printf("%10.3-c", 'x'));
	printf(": 10.-3c(%d)\n", printf("%10.-3c", 'x'));
	printf(": 10.>3c(%d)\n", printf("%10.>3c", 'x'));
	printf(": 10>c(%d)\n", printf("%10>c", 'x'));
	printf(": -10>c(%d)\n", printf("%-10>c", 'x'));
	printf(": 10-c(%d)\n", printf("%10-c", 'x'));
	printf(": 010c(%d)\n", printf("%010c", 'x'));
	printf(": 0-10c(%d)\n", printf("%0-10c", 'x'));

	printf("\n");

// . 뒤에 다른 flag 오는 경우
	char *df = "Hello World!";
	printf(": 10.5s(%d)\n", printf("%10.5s", df));
	printf(": 10.5.7s(%d)\n", printf("%10.5.7s", df));
	printf(": 10..5s(%d)\n", printf("%10..5s", df));
	printf(": 10.5.s(%d)\n", printf("%10.5.s", df));
	printf(": 10.-5s(%d)\n", printf("%10.-5s", df));
	printf(": 10.05s(%d)\n", printf("%10.05s", df));
	printf(": 010.5s(%d)\n", printf("%010.5s", df));
	int idf = 333333;
	printf(": 15.10d(%d)\n", printf("%15.10d", idf));
	printf(": 15.10.8d(%d)\n", printf("%15.10.8d", idf));
	printf(": 15.+10d(%d)\n", printf("%15.+10d", idf));
	printf(": 15.10+d(%d)\n", printf("%15.10+d", idf));
	printf(": 15.010d(%d)\n", printf("%15.010d", idf));
	printf(": 15.-10d(%d)\n", printf("%15.-10d", idf));
	printf(": 15. 10d(%d)\n", printf("%15. 10d", idf));

	printf("\n");

// 순서 상관없다. 모든 플래그는 후에 나온 것을 적용한다.
	printf(": 10.5-12s(%d)\n", printf("%10.5-12s", df));
	printf(": 15.10+20d(%d)\n", printf("%15.10+20d", idf));

	printf("\n");

	// p
	printf(": 20p(%d)\n", printf("%20p", df));
	printf(": 20.15p(%d)\n", printf("%20.15p", df));
	printf(": #20.15p(%d)\n", printf("%#20.15p", df));
	printf(": 20.5p(%d)\n", printf("%20.5p", df));
	printf(": 020.15p(%d)\n", printf("%020.15p", df));
	printf(": 020.5p(%d)\n", printf("%020.5p", df));
	printf(": -20.15p(%d)\n", printf("%-20.15p", df));
	printf(": 20.15-p(%d)\n", printf("%20.15-p", df));
	printf(": 020p(%d)\n", printf("%020p", df));
	printf(": 020-p(%d)\n", printf("%020-p", df));
	printf(": 20p(%d)\n", printf("%20p", 0));
	ft_printf(": 20p(%d)ft\n", ft_printf("%20p", 0));

		printf("\n");

	// x
	printf(": 20x(%d)\n", printf("%20x", df));
	printf(": 20.15x(%d)\n", printf("%20.15x", df));
	printf(": #20.15x(%d)\n", printf("%#20.15x", df));
	printf(": 20.5x(%d)\n", printf("%20.5x", df));
	printf(": 020.15x(%d)\n", printf("%020.15x", df));
	printf(": -20.15x(%d)\n", printf("%-20.15x", df));
	printf(": 20.15-x(%d)\n", printf("%20.15-x", df));
	printf(": 020x(%d)\n", printf("%020x", df));
	printf(": 020#x(%d)\n", printf("%020#x", df));
	printf(": 020-x(%d)\n", printf("%020-x", df));

		printf("\n");

	// X
	printf(": 20X(%d)\n", printf("%20X", df));
	ft_printf(": 20X(%d)ft\n", ft_printf("%20X", df));
	printf(": 20.15X(%d)\n", printf("%20.15X", df));
	ft_printf(": 20.15X(%d)ft\n", ft_printf("%20.15X", df));
	printf(": #20.15X(%d)\n", printf("%#20.15X", df));
	ft_printf(": #20.15X(%d)ft\n", ft_printf("%#20.15X", df));
	printf(": 20.5X(%d)\n", printf("%20.5X", df));
	ft_printf(": 20.5X(%d)ft\n", ft_printf("%20.5X", df));
	printf(": 020.15X(%d)\n", printf("%020.15X", df));
	ft_printf(": 020.15X(%d)ft\n", ft_printf("%020.15X", df));
	printf(": -20.15X(%d)\n", printf("%-20.15X", df));
	ft_printf(": -20.15X(%d)ft\n", ft_printf("%-20.15X", df));
	printf(": 20.15-X(%d)\n", printf("%20.15-X", df));
	ft_printf(": 20.15-X(%d)ft\n", ft_printf("%20.15-X", df));
	printf(": 020X(%d)\n", printf("%020X", df));
	ft_printf(": 020X(%d)ft\n", ft_printf("%020X", df));
	printf(": 020#X(%d)\n", printf("%020#X", df));
	ft_printf(": 020#X(%d)ft\n", ft_printf("%020#X", df));
	printf(": 020-X(%d)\n", printf("%020-X", df));
	ft_printf(": 020-X(%d)ft\n", ft_printf("%020-X", df));
	printf(": #20X(%d)\n", printf("%#20X", 0));
	ft_printf(": #20X(%d)ft\n", ft_printf("%#20X", 0));

			printf("\n");

	// u
	printf(": 20u(%d)\n", printf("%20u", idf));
	ft_printf(": 20u(%d)ft\n", ft_printf("%20u", idf));
	printf(": 20.15u(%d)\n", printf("%20.15u", idf));
	ft_printf(": 20.15u(%d)ft\n", ft_printf("%20.15u", idf));
	printf(": #20.15u(%d)\n", printf("%#20.15u", idf));
	ft_printf(": #20.15u(%d)ft\n", ft_printf("%#20.15u", idf));
	printf(": 20.5u(%d)\n", printf("%20.5u", idf));
	ft_printf(": 20.5u(%d)ft\n", ft_printf("%20.5u", idf));
	printf(": 020.15u(%d)\n", printf("%020.15u", idf));
	ft_printf(": 020.15u(%d)ft\n", ft_printf("%020.15u", idf));
	printf(": -20.15u(%d)\n", printf("%-20.15u", idf));
	ft_printf(": -20.15u(%d)ft\n", ft_printf("%-20.15u", idf));
	printf(": 20.15-u(%d)\n", printf("%20.15-u", idf));
	ft_printf(": 20.15-u(%d)ft\n", ft_printf("%20.15-u", idf));
	printf(": 020u(%d)\n", printf("%020u", idf));
	ft_printf(": 020u(%d)ft\n", ft_printf("%020u", idf));
	printf(": 020#u(%d)\n", printf("%020#u", idf));
	ft_printf(": 020#u(%d)ft\n", ft_printf("%020#u", idf));
	printf(": 020-u(%d)\n", printf("%020-u", idf));
	ft_printf(": 020-u(%d)ft\n", ft_printf("%020-u", idf));
	printf(": +.15u(%d)\n", printf("%+.15u", idf));
	ft_printf(": +.15u(%d)ft\n", ft_printf("%+.15u", idf));
	printf(": +u(%d)\n", printf("%+u", idf));
	ft_printf(": +u(%d)ft\n", ft_printf("%+u", idf));
	printf(": 20u(%d)\n", printf("%20u", -idf));
	ft_printf(": 20u(%d)ft\n", ft_printf("%20u", -idf));

	printf("\n");

	// d i 
	int last = 123456789;
	int end = -987654321;
	printf(": (+)20.15d(%d)\n", printf("%20.15d", last));
	printf(": (-)20.15i(%d)\n", printf("%20.15i", end));
	printf(": (+)+20.15i(%d)\n", printf("%+20.15i", last));
	printf(": (-)+20.15d(%d)\n", printf("%+20.15d", end));
	printf(": 20 .15d(%d)\n", printf("%20 .15d", last));
	printf(": 20 -.15i(%d)\n", printf("%20 -.15i", last));
	printf(": 20-.15d(%d)\n", printf("%20-.15d", last));
	printf(": 020i(%d)\n", printf("%020i", end));
	printf(": 0 20d(%d)\n", printf("%0 20d", last));
	printf(": 20 .20i(%d)\n", printf("%20 .20i", last));

	printf("\n");

	// null, nul
	printf(": s(%d)\n", printf("%s", 0));
	ft_printf(": s(%d)ft\n", ft_printf("%s", 0));
	printf(": 12s(%d)\n", printf("%12s", 0));
	ft_printf(": 12s(%d)ft\n", ft_printf("%12s", 0));
	printf(": 15.3(%d)\n", printf("%15.3s", 0));
	ft_printf(": 15.3(%d)ft\n", ft_printf("%15.3s", 0));
	printf(": s(%d)\n", printf("%s", ""));
	ft_printf(": s(%d)ft\n", ft_printf("%s", ""));
	printf(": c(%d)\n", printf("%c", 0));
	ft_printf(": c(%d)ft\n", ft_printf("%c", 0));
	printf(": 2c(%d)\n", printf("%2c", 0));
	ft_printf(": 2c(%d)ft\n", ft_printf("%2c", 0));
	printf(": -2c(%d)\n", printf("%-2c", 0));
	ft_printf(": -2c(%d)ft\n", ft_printf("%-2c", 0));
	printf(": (%d)\n", printf(""));
	ft_printf(": (%d)ft\n", ft_printf(""));
	printf(": sc(%d)\n", printf("%s%c", 0, 0));
	ft_printf(": sc(%d)ft\n", ft_printf("%s%c", 0, 0));

	printf("\n");

	// 랜덤이랑 %
	printf(": 20%%(%d)\n", printf("%20%"));
	ft_printf(": 20%%(%d)ft\n", ft_printf("%20%"));
	printf(": 20((%d)\n", printf("%20("));
	ft_printf(": 20((%d)ft\n", ft_printf("%20("));
	printf(": 20%%(%d)\n", printf("%20%", 42));
	ft_printf(": 20%%(%d)ft\n", ft_printf("%20%", 42));
	printf(": 20((%d)\n", printf("%20(", 42));
	ft_printf(": 20((%d)ft\n", ft_printf("%20(", 42));
	printf(": 20.11%%(%d)\n", printf("%20.11%"));
	ft_printf(": 20.11%%(%d)ft\n", ft_printf("%20.11%"));
	printf(": 20.11((%d)\n", printf("%20.11("));
	ft_printf(": 20.11((%d)ft\n", ft_printf("%20.11("));
	printf(": 20'\\0'(%d)\n", printf("%20\0"));
	ft_printf(": 20'\\0'(%d)ft\n", ft_printf("%20\0"));
	printf(": 20.11'\\0'(%d)\n", printf("%20.11\0"));
	ft_printf(": 20.11'\\0'(%d)ft\n", ft_printf("%20.11\0"));
	printf(": 20(%d)\n", printf("%20"));
	ft_printf(": 20(%d)ft\n", ft_printf("%20"));
	printf(": 20.11(%d)\n", printf("%20.11"));
	ft_printf(": 20.11(%d)ft\n", ft_printf("%20.11"));

	printf("\n");

	// 그 외
	printf("(%d)\n", printf(" %c %c %c ", '0', 0, '1'));
	ft_printf("(%d)ft\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	printf("(%d)\n", printf(" %c %c %c ", '2', '1', 0));
	ft_printf("(%d)ft\n", ft_printf(" %c %c %c ", '2', '1', 0));
	printf("(%d)\n", printf(" %c %c %c ", 0, '1', '2'));
	ft_printf("(%d)ft\n", ft_printf(" %c %c %c ", 0, '1', '2'));
	printf("(%d)\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	ft_printf("(%d)ft\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf(": .0i(%d)\n", printf("%.0i", 0));
	ft_printf(": .0i(%d)ft\n", ft_printf("%.0i", 0));
	printf(": 5.d(%d)\n", printf("%5.d", 0));
	ft_printf(": 5.d(%d)ft\n", ft_printf("%5.d", 0));
	printf(": .u(%d)\n", printf("%.u", 0));
	ft_printf(": .u(%d)ft\n", ft_printf("%.u", 0));
	printf(": .0i(%d)\n", printf("%.0i", 42));
	ft_printf(": .0i(%d)ft\n", ft_printf("%.0i", 42));
	printf(": 5.d(%d)\n", printf("%5.d", 42));
	ft_printf(": 5.d(%d)ft\n", ft_printf("%5.d", 42));
	printf(": .u(%d)\n", printf("%.u", 42));
	ft_printf(": .u(%d)\n", ft_printf("%.u", 42));
	printf(": 5.d(%d)\n", printf("%5.d", 0));
	ft_printf(": 5.d(%d)ft\n", ft_printf("%5.d", 0));
	printf(": +5.d(%d)\n", printf("%+5.d", 0));
	ft_printf(": +5.d(%d)ft\n", ft_printf("%+5.d", 0));
	printf(": +-5.d(%d)\n", printf("%+-5.d", 0));
	ft_printf(": +-5.d(%d)ft\n", ft_printf("%+-5.d", 0));
	printf(": 0#.u(%d)\n", printf("%0#.u", 0));
	ft_printf(": 0#.u(%d)ft\n", ft_printf("%0#.u", 0));
	printf(": +.0i(%d)\n", printf("%+.0i", 0));
	ft_printf(": +.0i(%d)ft\n", ft_printf("%+.0i", 0));
	printf(": 5.u(%d)\n", printf("%5.u", 0));
	ft_printf(": 5.u(%d)ft\n", ft_printf("%5.u", 0));
	printf(": -5.p(%d)\n", printf("%-5.p", 0));
	ft_printf(": -5.p(%d)ft\n", ft_printf("%-5.p", 0));
	printf(": #-5.u(%d)\n", printf("%#-5.u", 0));
	ft_printf(": #-5.u(%d)ft\n", ft_printf("%#-5.u", 0));
	printf(": .p(%d)\n", printf("%.p", 0));
	ft_printf(": .p(%d)ft\n", ft_printf("%.p", 0));

	return (0);
}

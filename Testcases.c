#include "main.h"

int main(void)
{
	int len, len2;
	
	len = _printf("%ld", 1024L);
	_printf("\n");
	len2 = printf("%ld", 1024L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	 
	len = _printf("%ld", -1024L);
	_printf("\n");
	len2 = printf("%ld", -1024L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ld", 0L);
	_printf("\n");
	len2 = printf("%ld", 0L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ld", LONG_MAX);
	_printf("\n");
	len2 = printf("%ld", LONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ld", LONG_MIN);
	_printf("\n");
	len2 = printf("%ld", LONG_MIN);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	len2 = printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);
	len2 = printf("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	len2 = printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li", 1024L);
	_printf("\n");
	len2 = printf("%li", 1024L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li", -1024L);
	_printf("\n");
	len2 = printf("%li", -1024L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li", 0L);
	_printf("\n");
	len2 = printf("%li", 0L);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li", LONG_MAX);
	_printf("\n");
	len2 = printf("%li", LONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li", LONG_MIN);
	_printf("\n");
	len2 = printf("%li", LONG_MIN);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %li bytes in %li KB\n", 1024L, 1L);
	len2 = printf("There is %li bytes in %li KB\n", 1024L, 1L);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li - %li = %li\n", 1024L, 2048L, -1024L);
	len2 = printf("%li - %li = %li\n", 1024L, 2048L, -1024L);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	len2 = printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lu", 1024UL);
	_printf("\n");
	len2 = printf("%lu", 1024UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lu", 0UL);
	_printf("\n");
	len2 = printf("%lu", 0UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lu", ULONG_MAX);
	_printf("\n");
	len2 = printf("%lu", ULONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	len2 = printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lo", 1024UL);
	_printf("\n");
	len2 = printf("%lo", 1024UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lo", 0UL);
	_printf("\n");
	len2 = printf("%lo", 0UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lo", ULONG_MAX);
	_printf("\n");
	len2 = printf("%lo", ULONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	len2 = printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lx", 1024UL);
	_printf("\n");
	len2 = printf("%lx", 1024UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lx", 0UL);
	_printf("\n");
	len2 = printf("%lx", 0UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lx", ULONG_MAX);
	_printf("\n");
	len2 = printf("%lx", ULONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	len2 = printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lX", 1024UL);
	_printf("\n");
	len2 = printf("%lX", 1024UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lX", 0UL);
	_printf("\n");
	len2 = printf("%lX", 0UL);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lX", ULONG_MAX);
	_printf("\n");
	len2 = printf("%lX", ULONG_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	len2 = printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd", 1024);
	_printf("\n");
	len2 = printf("%hd", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd", -1024);
	_printf("\n");
	len2 = printf("%hd", -1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd", 0);
	_printf("\n");
	len2 = printf("%hd", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd", SHRT_MAX);
	_printf("\n");
	len2 = printf("%hd", SHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd", SHRT_MIN);
	_printf("\n");
	len2 = printf("%hd", SHRT_MIN);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %hd bytes in %hd KB\n", 1024, 1);
	len2 = printf("There is %hd bytes in %hd KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd - %hd = %hd\n", 1024, 2048, -1024);
	len2 = printf("%hd - %hd = %hd\n", 1024, 2048, -1024);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	len2 = printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi", 1024);
	_printf("\n");
	len2 = printf("%hi", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi", -1024);
	_printf("\n");
	len2 = printf("%hi", -1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi", 0);
	_printf("\n");
	len2 = printf("%hi", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi", SHRT_MAX);
	_printf("\n");
	len2 = printf("%hi", SHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi", SHRT_MIN);
	_printf("\n");
	len2 = printf("%hi", SHRT_MIN);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %hi bytes in %hi KB\n", 1024, 1);
	len2 = printf("There is %hi bytes in %hi KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi - %hi = %hi\n", 1024, 2048, -1024);
	len2 = printf("%hi - %hi = %hi\n", 1024, 2048, -1024);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hi + %hi = %hi\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	len2 = printf("%hi + %hi = %hi\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hu", 1024);
	_printf("\n");
	len2 = printf("%hu", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hu", 0);
	_printf("\n");
	len2 = printf("%hu", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hu", USHRT_MAX);
	_printf("\n");
	len2 = printf("%hu", USHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %hu bytes in %hu KB\n", 1024, 1);
	len2 = printf("There is %hu bytes in %hu KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ho", 1024);
	_printf("\n");
	len2 = printf("%ho", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ho", 0);
	_printf("\n");
	len2 = printf("%ho", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ho", USHRT_MAX);
	_printf("\n");
	len2 = printf("%ho", USHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %ho bytes in %ho KB\n", 1024, 1);
	len2 = printf("There is %ho bytes in %ho KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%ho - %ho = %ho\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%ho - %ho = %ho\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hx", 1024);
	_printf("\n");
	len2 = printf("%hx", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hx", 0);
	_printf("\n");
	len2 = printf("%hx", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hx", USHRT_MAX);
	_printf("\n");
	len2 = printf("%hx", USHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %hx bytes in %hx KB\n", 1024, 1);
	len2 = printf("There is %hx bytes in %hx KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hX", 1024);
	_printf("\n");
	len2 = printf("%hX", 1024);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hX", 0);
	_printf("\n");
	len2 = printf("%hX", 0);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hX", USHRT_MAX);
	_printf("\n");
	len2 = printf("%hX", USHRT_MAX);
	_printf("\nLen:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("There is %hX bytes in %hX KB\n", 1024, 1);
	len2 = printf("There is %hX bytes in %hX KB\n", 1024, 1);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);
	
	len = _printf("%h\n");
	len2 = printf("%h\n");
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);

	len = _printf("%l\n");
	len2 = printf("%l\n");
	_printf("Len:[%d]\tLen2:[%d]\n", len, len2);

	return (0);
}

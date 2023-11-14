#include <limits.h>
#include <stdio.h>
#include <math.h>

#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int len = 0;
	int len2 = 0;
	void *addr = 0;
	long int ui64 = 0;


	_printf("Formatted: %d %i %X %p %o %hd %hi %hhu %hhd\r\n",
				1234, -5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (char)-10);

	_printf("Formatted: %ld %lx %lld %llx\r\n",
				-100000000l, 0xdeadbeeful, 10200300400l, 0xdeadbeeffeebdaedul);
	printf("Formatted: %ld %lx %lld %llx\r\n",
				-100000000l, 0xdedbeeful, 10200300400l, 0xdeadbeeffeebdaedul);
	
	addr = (void *)0x7ffe637541f0;
	
	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len2:[%d]\n", len2);
	len = _printf("%r\n", "Unknown");
	_printf("Len:[%d]\n", len);
	_printf("%b\n", 8);
	_printf("%b\n", 7);
	_printf("%b\n", 9);
	_printf("%b\n", 65536);
	_printf("%b\n", 0xffffffffffffffff);

	ui64 = 4294967297;
	_printf("%lu\n", ui64);

	ui64 = (0xffffffffffffffff); /*max 64-bit unsigned int possible value*/
	_printf("%lu\n", ui64);

	_printf("%S\n", "Best\nSchool");

	_printf("\nFlags specifiers tests:\n\n");
	_printf("Preceding with blanks: %10d \n", 1977);
	printf("Preceding with blanks: %10d \n", 1977);
	_printf("Preceding with zeros: %010d \n", 1977);
	printf("Preceding with zeros: %010d \n", 1977);
	_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	_printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	_printf("Width trick: %*d \n", 5, 10);
	printf("Width trick: %*d \n", 5, 10);


	return (0);
}
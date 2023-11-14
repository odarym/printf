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
	unsigned int ui = 0;
	void *addr = 0;
	long int ui32 = 0;
	int num = 10;

	_printf("Formatted: %d %i %x %p %o %hd %hi %hhu %hhd\r\n",
				1234, -5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (char)-10);
	printf("Formatted: %d %i %x %p %o %hd %hi %hhu %hhd\r\n",
				1234, -5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (char)-10);
	_printf("Formatted: %ld %lx %lld %llx\r\n",
				-100000000l, 0xdeadbeeful, 10200300400l, 0xdeadbeeffeebdaedul);
	printf("Formatted: %ld %lx %lld %llx\r\n",
				-100000000l, 0xdeadbeeful, 10200300400l, 0xdeadbeeffeebdaedul);

	len = _printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	/*
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	*/
	_printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len2:[%d]\n", len2);
	len = _printf("%r\n", "Unknown");
	_printf("Len:[%d]\n", len);
	_printf("%b\n", 8);
	_printf("%b\n", 7);
	_printf("%b\n", 9);
	_printf("%b\n", 65536);
	_printf("%b\n", 0x9000000000000000);
    /* print value using %d*/
	_printf("Value of num using %%d is = %d\n", num);
    /* print value using %i*/
    _printf("Value of num using %%i is = %i\n", num);
	/* Max 32-bit int value = 4294967296 - 1*/
	/**
	 * 1000000000000000000000000000000000000000000000000000000000000000
	 * 1000000000000000000000000000000000000000000000000000000000000000
	*/
	ui32 = 4294967297;
	_printf("%lu\n", ui32);
	ui32 = 0x8000000000000000;
	_printf("%lu\n", ui32);
	_printf("%S\n", "Best\nSchool");

	/*
	_printf("\nFlags specifiers tests\n\n");
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
	*/

	return (0);
}
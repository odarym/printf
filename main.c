#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	/*
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	*/
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%r\n", "Unknown");
	_printf("Len:[%d]\n", len);
	printf("Unknown:[%r]\n");
	_printf("%b\n", 8);
	_printf("%b\n", 7);
	_printf("%b\n", 9);

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
	
	return (0);
}
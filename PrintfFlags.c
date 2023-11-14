#include "main.h"

/**
 * PrintfFlags - Handle flag specifiers
 *
 * @flag: The flag passed
 *
 * Return: Print count
*/
int PrintfFlags(char flag, va_list arguments)
{
	char specifier = va_arg (arguments, int);
	int count = 0;

	/* temporary to get rid of compiler warnings */
	flag++;
	count++;
	specifier++;

	return (count);
}

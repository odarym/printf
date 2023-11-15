#include "main.h"

/**
 * PrintfFlags - Handle flag specifiers
 *
 * @flag: The flag passed
 * @arguments: Variable argument list
 *
 * Return: Print count
 */
int PrintfFlags(char flag, va_list arguments)
{
	char specifier = va_arg(arguments, int);
	int count = 0;

    switch (f lag)
    {
        case '+':
            count++;
            Putchar(flag);
            Putchar(specifier);
            /*Handle behavior for '+' flag in different states if needed*/
            break;
        case '-':
            count++;
            Putchar(flag);
            Putchar(specifier);
            /*Handle behavior for '-' flag in different states if needed*/
            break;
        case ' ':
            count++;
            Putchar(flag);
            Putchar(specifier);
            /*Handle behavior for ' ' flag in different states if needed*/
            break;
        case '#':
            count++;
            Putchar(flag);
            Putchar(specifier);
            /*Handle behavior for '#' flag in different states if needed*/
            break;
        case '0':
            count++;
            Putchar(flag);
            Putchar(specifier);
            /*Handle behavior for '0' flag in different states if needed*/
            break;
    }

	return (count);
}

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

	switch (flag)
	{
		case '+':
        /*Handle behavior for '+' flag in diffrent states*/
			Putchar(flag);
			if (specifier == 'd' || specifier == 'i')
			{
				int number = va_arg(arguments, int);
				if (number >= 0)
				{
					Putchar('+');
					count++;
				}
			}
			break;
		case '-':
			/*Handle behavior for '-' flag in different states if needed*/
			break;
		case ' ':
		Putchar(flag);
			break;
		case '#':
			Putchar(flag);
			if (specifier == 'x' || specifier == 'X' || specifier == 'o')
			{
				/* Handle '#' for hex and octal*/
				count += 2;
				/* Assuming a 0x or 0 prefix is added*/
			}
			break;
		case '0':
			if (specifier == 'a' || specifier == 'A' || specifier == 'e' || specifier == 'E' ||
				specifier == 'f' || specifier == 'F' || specifier == 'g' || specifier == 'G')
			{
				/* Handle '#' for floating-point formats*/
				Putchar('0');
				count++;
			}
			break;
	}
	return (count);
}

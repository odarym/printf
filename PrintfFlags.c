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
			Putchar(flag);
			Putchar(specifier);
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
			/*Handle behavior for ' ' flag in different states if needed*/
			break;
		case '#':
			Putchar(flag);
			Putchar(specifier);
			/*Handle behavior for '#' flag in different states if needed*/
			break;
		case '0':
			Putchar(flag);
			Putchar(specifier);
			/*Handle behavior for '0' flag in different states if needed*/
			break;
	}
	return (count);
}

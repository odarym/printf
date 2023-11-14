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

		switch (flag)
	{
		case '+':
			count++;
			{
				if (count[], "%2d" == 0)
				{
					count = true;
				}
			}
			/*Print the flag for now. Checking if flag was received correctly*/
			Putchar(flag);
			Putchar(specifier);
			/** Expected flag behaviour
			 * Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.
			 * By default, only negative numbers are preceded with a - sign.
			*/

			break;
		case '-':
			count++;
			/*Print the flag for now. Checking if flag was received correctly*/
			Putchar(flag);
			Putchar(specifier);
			/** Expected flag behaviour
			 * Left-justify within the given field width; Right justification is the default (see width sub-specifier).
			*/
			break;
		case ' ':
			count++;
			/*Print the flag for now. Checking if flag was received correctly*/
			Putchar(flag);
			Putchar(specifier);
			/** Expected flag behaviour
			 * If no sign is going to be written, a blank space is inserted before the value.
			*/
			break;
		case '#':
			count++;
			/*Print the flag for now. Checking if flag was received correctly*/
			Putchar(flag);
			Putchar(specifier);
			/** Expected flag behaviour
			 * Used with o, x or X specifiers the value is preceeded with
			 *  0, 0x or 0X respectively for values different than zero.
			 *
			 * Used with a, A, e, E, f, F, g or G it forces the 
			 *  written output to contain a decimal point even if no more digits follow.
			 *   By default, if no digits follow, no decimal point is written.
			*/
			break;
		case '0':
			count++;
			/*Print the flag for now. Checking if flag was received correctly*/
			Putchar(flag);
			Putchar(specifier);
			/** Expected flag behaviour
			 * Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
			*/
			break;
	}

	return (count);
}

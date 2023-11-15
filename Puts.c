#include "main.h"

/**
 * Puts - put a string (character array) onto the screen
 *
 * @string: The string to print
 *
 * Return: 0 for failure and the number of characters printed for sucess
*/
int Puts(char *string)
{
	if (!string)
	{
		return (write(1, "(null)", 6));
	}

	return (write(1, string, strlen(string)));
}


/**
 * PutsCustom - put a string in a custom way if printf
 *  receives S custom specifier
 *
 * @string: The string to print
 *
 * Return: 0 for failure and the number of characters printed for sucess
*/
int PutsCustom(char *string)
{
	uint8_t i = 0;
	int length = 0, count = 0;
	char *buffer = NULL;

	if (!string)
		return (0);

	length = strlen(string);
	for (; i < length; i++)
	{
		/*Range of non printable ascii characters*/
		if ((string[i] < 0) || (string[i] < 32) || (string[i] > 126))
		{
			count += Puts("\\x");
			buffer = (char *)ConvertBase(string[i], 16);
			/*Single digit hex number*/
			if ((string[i] < 17))
			{
				count += Putchar('0');
				count += Putchar(buffer[0]);
				continue;
			}
			else
			{
				count += Putchar(buffer[0]);
				count += Putchar(buffer[1]);
			}
			/*Skip to the next loop iteration*/
			continue;
		}

		count += Putchar(string[i]);
	}

	return (count);
}


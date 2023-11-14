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
	int length = 0;

	if (!string)
		return (0);

	length = strlen(string);
	write(1, string, length);

	return (length);
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
		if ((string[i] < 32) || (string[i] > 126))
		{
			count += Puts("\\x");
			buffer = (char *)ConvertBase(string[i], 16);
			/*Single digit hex number*/
			if ((string[i] < 17))
			{
				Putchar('0');
				Putchar(buffer[0]);
				count += 2;
				continue;
			}
			else
			{
				Putchar(buffer[0]);
				Putchar(buffer[1]);
				count += 2;
			}
			/*Skip to the next loop iteration*/
			continue;
		}

		Putchar(string[i]);
		count++;
	}

	return (count);
}


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

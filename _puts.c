#include "main.h"

/**
 * _puts - put a string (character array) onto the screen
 *
 * @string: The string to print
 *
 * Return: -1 for failure and the length printed for sucess
*/

int _puts(char *string)
{
	uint16_t length = 0;

	if (!string)
		return (-1);

	length = strlen(string);
	write(1, string, length);
	return (length);
}

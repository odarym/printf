#include "main.h"

/**
 * PutsReverse - Print string in reverse
 *
 * @string: The string being printed in reverse
 * Return:void
*/

int PutsReverse(char *string)
{
	int stringLength = strlen(string);
	int count = 0;

	count = stringLength;
	if (stringLength > 0)
	{
		do {
			Putchar(string[--stringLength]);
		} while (stringLength > 0);
	}

	return (count);
}


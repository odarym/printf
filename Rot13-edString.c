#include "main.h"

/**
 * PutsRot13 - Print string in rot13 form
 *
 * @string: The string being printed in rot13
 *
 * Return:void
*/

int PutsRot13(char *string)
{
	uint8_t i = 0;
	int stringLength = strlen(string);
	int count = 0;
	char c = 0;

	count = stringLength;

	if (!string)
		return (0);

	for (; string[i] != '\0'; i++)
	{
		c = string[i];

		if (c >= 'a' && c <= 'z')
		{
			Putchar((c - 'a' + 13) % 26 + 'a');
		}
		else if (c >= 'A' && c <= 'Z')
		{
			Putchar((c - 'A' + 13) % 26 + 'A');
		}
		else
		{
			Putchar(c);
		}
	}

	return (count);
}


#include "main.h"

/**
 * Putchar - Put a single character onto the screen
 *
 * @ch: The char to write
 *
 * Return: 1
*/

int Putchar(char ch)
{
	return (write(1, &ch, 1));
}



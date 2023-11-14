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
	write(1, &ch, 1);
	return (1);
}



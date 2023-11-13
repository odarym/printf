#include "main.h"

/**
 * Putchar - Put a single character onto the screen
 *
 * @ch: The char to write
 *
 * Return: void
*/

void Putchar(char ch)
{
	write(1, &ch, 1);
}



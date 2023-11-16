#include "main.h"

/**
 * DecimalToBinary - Convert from deciml to binary
 *  and print the bits
 *
 * @number: The base 10 number to convert
 *
 * Return: The number of digits in the binary number
*/
int DecimalToBinary(uint64_t number)
{
	const char binChars[] = {"01"};
	char buffer[63] = { 0 }; /*A maximum of 32 bit value*/
	uint8_t count = 0;
	int i = 0;

	do {
		int rem = number % 2;

		number /= 2;
		buffer[i++] = binChars[rem];
	} while (number > 0);


	while (--i > -1)
	{
		Putchar(buffer[i]);
		count++;
	}

	return (count);
}

#include "main.h"

/**
 * ConvertBase - Convert a number in decimal base to the specified one
 *
 * @number: The base 10 number to convert
 * @radix: The base to convert the number to
 *
 * Return: The number of digits in the binary number
*/
char *ConvertBase(uint64_t number, uint8_t radix)
{
	const char hexChars[] = {"0123456789ABCDEF"};
	char buffer[2] = { '0', '0' };
	char *bufferPtr = (char *)&(buffer[0]);
	char reverseBuffer[2] = { '0' };
	uint8_t count = 0;
	int i = 0;

	do {
		int rem = number % radix;

		number /= radix;
		reverseBuffer[i++] = hexChars[rem];
	} while (number > 0);


	while (--i > -1)
	{
		uint8_t j = 0;

		buffer[j++] = reverseBuffer[i];
		count++;
	}

	return (bufferPtr);
}

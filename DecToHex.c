#include "main.h"

/**
 * ConvertBase - Convert a decimal value to hex
 *
 * @number: The base 10 number to convert
 * @outBuffer: The buffer that stores the result
 *
 * Return: The number of digits in the binary number
*/
void DecToHex(char *outBuffer, uint64_t number)
{
	const char hexChars[] = {"0123456789ABCDEF"};

	char reverseBuffer[3] = { 0 };

	int i = 0, j = 0;
	int rem = 0;

	do {
		rem = number % 16;

		number /= 16;
		reverseBuffer[i++] = hexChars[rem];
	} while (number > 0);


	while (--i > -1)
		outBuffer[j++] = reverseBuffer[i];
}

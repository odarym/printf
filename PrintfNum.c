#include "PrintfHelpers.h"

/**
 * PrintfNum - Assist printf in formatting numbers before printing
 *
 * @currentStatePtr: a structure holding the current
 * state of printf needed by PrintfNum for processing
 *
 * Return: the number of characters in the value
*/
uint8_t PrintfNum(PrintfStateHolderStruct_t *currentStatePtr)
{
	char buffer[32] = { 0 };
	uint64_t number = 0;
	int8_t numSign = 1, i = 0, j = 0;
	uint8_t count = 0;
	char hexChars[] = {"0123456789abcdef"};

	uint64_t arg = va_arg(currentStatePtr->args, uint64_t);

	/*Process length*/
	switch (currentStatePtr->length)
	{
		case LEN_SHORT_SHORT:
			if (currentStatePtr->sign)
			{
				int n = arg;

				if (n < 0)
				{
					currentStatePtr->printSignAlways = false;
					n = -n, numSign = -1;
				}
				number = (unsigned short)n;
			}
			else
				number = (unsigned short)arg;
			break;
		case LEN_SHORT:
		case LEN_DEFAULT:
			if (currentStatePtr->sign)
			{
				int n = arg;

				if (n < 0)
				{
					currentStatePtr->printSignAlways = false;
					n = -n, numSign = -1;
				}
				number = (unsigned int)n;
			}
			else
				number = (unsigned int)arg;
			break;
		case LEN_LONG:
		case LEN_LONG_LONG:
			if (currentStatePtr->sign)
			{
				int64_t n = arg;

				if (n < 0)
				{
					currentStatePtr->printSignAlways = false;
					n = -n, numSign = -1;
				}
				number = (uint64_t)n;
			}
			else
			{
				number = (uint64_t)arg;
			}
			break;
	}
	/*Convert number to ascii */
	/*Convert hexChars to uppercase if X format is used*/
	if (currentStatePtr->hexUpper)
		for (j = 10; j < 16; j++)
			hexChars[j] -= ' ';

	do {
		uint32_t rem = number % currentStatePtr->radix;

		number /= currentStatePtr->radix;
		buffer[i++] = hexChars[rem];
	} while (number > 0);

	currentStatePtr->width -= i;
	if ((currentStatePtr->width > 0) && (currentStatePtr->flags == FLAG_NONE))
	{
		while (currentStatePtr->width--)
			Putchar(' ');
	}
	else if ((currentStatePtr->flags == FLAG_ZERO) && (currentStatePtr->width > 0))
	{
		while (currentStatePtr->width--)
			Putchar('0');
	}

	/*Place sign*/
	if (currentStatePtr->sign && numSign < 0 && !currentStatePtr->printSignAlways)
		buffer[i++] = '-';
	else if (currentStatePtr->printSignAlways)
		count += Putchar('+');
	else if (currentStatePtr->flags == FLAG_SPACE)
		count += Putchar(' ');

	while (--i > -1)
		count += Putchar(buffer[i]);

	return (count);
}


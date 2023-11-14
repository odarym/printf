#include "main.h"


#define PRINTF_STATE_NORMAL 0
#define PRINTF_STATE_LENGTH 1
#define PRINTF_STATE_LENGTH_SHORT 2
#define PRINTF_STATE_LENGTH_LONG 3
#define PRINTF_STATE_SPEC 4

#define PRINTF_LENGTH_DEFAULT 0
#define PRINTF_LENGTH_SHORT_SHORT 1
#define PRINTF_LENGTH_SHORT	2
#define PRINTF_LENGTH_LONG	3
#define PRINTF_LENGTH_LONG_LONG	4


uint8_t PrintfNum(unsigned long int arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper);


/**
 * _printf - Print a formatted string
 *
 * @format: The string specifying the format
 *
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	uint16_t i = 0;
	int count = 0;

	va_list args;
	uint8_t state = PRINTF_STATE_NORMAL;
	uint8_t length = PRINTF_LENGTH_DEFAULT;
	uint8_t base = 10;
	bool hexUpper = false;
	bool sign = false;


	/*Check the validity of the format string*/
	if (!format)
		return (-1);

	va_start(args, format);

	for (; format[i]; i++)
	{
		switch (state)
		{
			case PRINTF_STATE_NORMAL:
				switch (format[i])
				{
					case '%':
						state = PRINTF_STATE_LENGTH;
						break;
					default:
						Putchar(format[i]);
						count++;
						break;
				}
				break;

			case PRINTF_STATE_LENGTH:
				switch (format[i])
				{
					case 'h':
						length = PRINTF_LENGTH_SHORT;
						state = PRINTF_STATE_LENGTH_SHORT;
						break;
					case 'l':
						length =  PRINTF_LENGTH_LONG;
						break;
					default:
						goto PRINTF_STATE_SPEC_;
				}
				break;

			case PRINTF_STATE_LENGTH_SHORT:
				if (format[i] == 'h')
				{
					length = PRINTF_LENGTH_SHORT_SHORT;
					state = PRINTF_STATE_SPEC;
				}
				else
				{
					goto PRINTF_STATE_SPEC_;
				}
				break;
			case PRINTF_STATE_LENGTH_LONG:
				if (format[i] == 'l')
				{
					length = PRINTF_LENGTH_LONG_LONG;
					state = PRINTF_STATE_SPEC;
				}
				else
				{
					goto PRINTF_STATE_SPEC_;
				}
				break;

			case PRINTF_STATE_SPEC:
PRINTF_STATE_SPEC_:
				switch (format[i])
				{
					case 'c':
						Putchar((va_arg(args, int)));
						count++;
						break;
					case 's':
						count += Puts(va_arg(args, char*));
						break;
					case 'r':
						count += PutsReverse(va_arg(args, char*));
						break;
					case 'S':
						count += PutsCustom(va_arg(args, char *));
						break;
					case '%':
						Putchar('%');
						count++;
						break;
					case 'b':
						count += DecimalToBinary(va_arg(args, long int));
						break;
					case 'd':
					case 'i':
						base = 10;
						sign = true;
						count += PrintfNum(va_arg(args, unsigned long), length, sign, base, hexUpper);
						break;
					case 'u':
						base = 10;
						sign = false;
						count += PrintfNum(va_arg(args, unsigned long),
													length, sign, base, hexUpper);
						break;
					case 'x':
						base = 16;
						sign = false;
						count += PrintfNum(va_arg(args, long int), length, sign, base, hexUpper);
						break;
					case 'X':
					/*Print hex chars in uppercase*/
						base = 16;
						sign = false;
						hexUpper = true;
						count += PrintfNum(va_arg(args, long int),
											length, sign, base, hexUpper);
						break;
					case 'p':
						count += Puts("0x");
						base = 16;
						sign = false;
						length = PRINTF_LENGTH_LONG_LONG;
						count += PrintfNum(va_arg(args, unsigned long int),
											length, sign, base, hexUpper);
						break;
					case 'o':
						base = 8;
						sign = false;
						count += PrintfNum(va_arg(args, long int), length, sign, base, hexUpper);
						break;

					case '+':
					case '-':
					case ' ':
					case '#':
					case '0':
					count += PrintfFlags(format[i], args);
					break;

					/*Ignore invalid specifier characters for now*/
					default:
						Putchar(format[i - 1]);
						Putchar(format[i]);
						count += 2;
						break;
				}

				/*Reset state to NORMAL*/
				#undef PRINTF_HEX_UPPER
				state = PRINTF_STATE_NORMAL;
				length = PRINTF_LENGTH_DEFAULT;
				base = 10;
				sign = false;
				break;
		}
	}
	va_end(args);

	if (format[i - 1] == '%')
		count = -1;

	return (count);
}

/**
 * PrintfNum - Assist printf in formatting numbers before printing
 *
 * @arg: The number to format
 * @length: The state to format to
 * @sign: The number sign
 * @base: The number base
 *
 * Return: the number of characters in the value
*/
uint8_t PrintfNum(unsigned long int arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper)
{
	char buffer[32] = { 0 };
	unsigned long int number = 0;
	int8_t numSign = 1;
	int8_t i = 0, j = 0;
	uint8_t count = 0;
	char hexChars[] = {"0123456789abcdef"};

	/*Process length*/
	switch (length)
	{
		case PRINTF_LENGTH_SHORT_SHORT:
		case PRINTF_LENGTH_SHORT:
		case PRINTF_LENGTH_DEFAULT:
			if (sign)
			{
				int n = arg;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (int)n;
			}
			else
			{
				number = (unsigned int)arg;
			}
			break;
		case PRINTF_LENGTH_LONG:
		case PRINTF_LENGTH_LONG_LONG:
			if (sign)
			{
				long int n = arg;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (long int)n;
			}
			else
			{
				number = (unsigned long int)arg;
			}
			break;
	}
	/*Convert number to ascii */
	/*Convert hexChars to uppercase if X specifier is used*/
	if (hexUpper)
		for (j = 10; j < 16; j++)
			hexChars[j] -= ' ';

	do {
		uint32_t rem = number % base;

		number /= base;
		buffer[i++] = hexChars[rem];
	} while (number > 0);

	/*Place sign*/
	if (sign && numSign < 0)
		buffer[i++] = '-';

	while (--i > -1)
	{
		Putchar(buffer[i]);
		count++;
	}

	return (count);
}


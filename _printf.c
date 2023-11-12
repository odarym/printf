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


uint8_t PrintfNum(int argument, uint8_t lengthState, bool sign, uint8_t base);


/**
 * _printf - Print a formatted string
 *
 * @format: The string specifying the format
 *
 * Return: the number of characters printed
 *  (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	uint16_t i = 0;
	uint16_t count = 0;

	va_list args;
	uint8_t state = PRINTF_STATE_NORMAL;
	uint8_t lengthState = PRINTF_LENGTH_DEFAULT;
	uint8_t base = 10;
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
						_putchar(format[i]);
						count++;
						break;
				}
				break;

			case PRINTF_STATE_LENGTH:
				switch (format[i])
				{
					case 'h':
						lengthState = PRINTF_LENGTH_SHORT;
						state = PRINTF_STATE_LENGTH_SHORT;
						break;
					case 'l':
						lengthState =  PRINTF_LENGTH_LONG;
						break;
					default:
						goto PRINTF_STATE_SPEC_;
				}
				break;

			case PRINTF_STATE_LENGTH_SHORT:
				if (format[i] == 'h')
				{
					lengthState = PRINTF_LENGTH_SHORT_SHORT;
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
					lengthState = PRINTF_LENGTH_LONG_LONG;
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
						_putchar((va_arg(args, int)));
						count++;
						break;
					case 's':
						count += _puts(va_arg(args, char*));
						break;
					case '%':
						_putchar('%');
						count++;
						break;
					case 'd':
					case 'i':
						base = 10;
						sign = true;
						count += PrintfNum(va_arg(args, int), lengthState, sign, base);
						break;
					case 'u':
						base = 10;
						sign = false;
						count += PrintfNum(va_arg(args, int), lengthState, sign, base);
						break;
					case 'X':
					case 'x':
					case 'p':
						base = 16;
						sign = false;
						count += PrintfNum(va_arg(args, int), lengthState, sign, base);
						break;
					case 'o':
						base = 8;
						sign = false;
						count += PrintfNum(va_arg(args, int), lengthState, sign, base);
						break;

					/*Ignore invalid specifier characters for now*/
					default:
						_putchar(format[i - 1]);
						_putchar(format[i]);
						count += 2;
						break;
				}

				/*Reset state to NORMAL*/
				state = PRINTF_STATE_NORMAL;
				lengthState = PRINTF_LENGTH_DEFAULT;
				base = 10;
				sign = false;
				break;
		}
	}
	va_end(args);

	return (count);
}

/**
 * PrintfNum - Assist printf in formatting numbers before printing
 *
 * @argument: The number to format
 * @lengthState: The state to format to
 * @sign: The number sign
 * @base: The number base
 *
 * Return: the number of characters in the value
*/
uint8_t PrintfNum(int argument, uint8_t lengthState, bool sign, uint8_t base)
{
	char buffer[32] = { 0 };
	uint64_t number = 0;
	int8_t numSign = 1;
	int8_t i = 0;
	uint8_t count = 0;
	const char hexChars[] = {"0123456789abcdef"};

	switch (lengthState)
	{
		case PRINTF_LENGTH_SHORT_SHORT:
		case PRINTF_LENGTH_SHORT:
		case PRINTF_LENGTH_DEFAULT:
			if (sign)
			{
				int n = argument;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (int)n;
			}
			else
			{
				number = (unsigned int)argument;
			}
			break;
		case PRINTF_LENGTH_LONG:
			if (sign)
			{
				long int n = argument;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (uint64_t)n;
			}
			else
			{
				number = (unsigned long int)argument;
			}
			break;
		case PRINTF_LENGTH_LONG_LONG:
			if (sign)
			{
				int64_t n = argument;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (uint64_t)n;
			}
			else
			{
				number = (uint64_t)argument;
			}
			break;
	}

	/*Convert number to string*/
	do {
		uint32_t rem = number % base;

		number /= base;
		buffer[i++] = hexChars[rem];
	} while (number > 0);

	/*Place sign*/
	if (sign && numSign < 0)
	{
		buffer[i++] = '-';
	}

	while (--i > -1)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}


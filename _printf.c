#include "_printf.h"


/**
 * _printf - Print a formatted string
 *
 * @format: The string specifying the format
 *
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	PrintfState state = NORMAL;
	PrintfLengthState length = LEN_DEFAULT;
	uint8_t base = 10;
	bool hexUpper = false, sign = false;

	if (!format) /*Check the validity of the format string*/
		return (-1);

	va_start(args, format);
	for (; format[i]; i++)
	{
		switch (state)
		{
			case NORMAL:
				switch (format[i])
				{
					case '%':
						state = LENGTH;
						break;
					default:
						count += Putchar(format[i]);
						break;
				}
				break;
			case FLAG:
				switch (format[i])
				{
					case '+':
					case '-':
					case ' ':
					case '#':
					case '0':
						count += PrintfFlags(format[i], args);
						break;
				default:
					break;
				}
				break;
			case LENGTH:
				switch (format[i])
				{
					case 'h':
						length = LEN_SHORT, state = SHORT;
						break;
					case 'l':
						length =  LEN_LONG;
						break;
					default:
						goto PRINTF_STATE_SPEC_;
				}
				break;
			case SHORT:
				if (format[i] == 'h')
					length = LEN_SHORT_SHORT, state = SPEC;
				else
					goto PRINTF_STATE_SPEC_;

				break;
			case LONG:
				if (format[i] == 'l')
					length = LEN_LONG_LONG, state = SPEC;
				else
					goto PRINTF_STATE_SPEC_;
				break;
			case SPEC:
PRINTF_STATE_SPEC_:
				PrintfSpecifierParser(&count, i, format, args, base, sign, length, hexUpper);
				/*Reset state to NORMAL*/
				sign = false, hexUpper = false, base = 10,
				state = NORMAL, length = LEN_DEFAULT;
				break;
		}
	}
	va_end(args);

	if ((format[i - 1] == '%') && (format[i - 3]))
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
 * @hexUpper: The case of hex chars
 *
 * Return: the number of characters in the value
*/
uint8_t PrintfNum(uint64_t arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper)
{
	char buffer[32] = { 0 };
	uint64_t number = 0;
	int8_t numSign = 1, i = 0, j = 0;
	uint8_t count = 0;
	char hexChars[] = {"0123456789abcdef"};

	/*Process length*/
	switch (length)
	{
		case LEN_SHORT_SHORT:
			if (sign)
				{
					int n = arg;

					if (n < 0)
					{
						n = -n;
						numSign = -1;
					}
					number = (short)n;
				}
				else
				{
					number = (unsigned short)arg;
				}
				break;
		case LEN_SHORT:
		case LEN_DEFAULT:
			if (sign)
			{
				int n = arg;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (unsigned int)n;
			}
			else
			{
				number = (unsigned int)arg;
			}
			break;
		case LEN_LONG:
		case LEN_LONG_LONG:
			if (sign)
			{
				int64_t n = arg;

				if (n < 0)
				{
					n = -n;
					numSign = -1;
				}
				number = (int64_t)n;
			}
			else
			{
				number = (uint64_t)arg;
			}
			break;
	}
	/*Convert number to ascii */
	/*Convert hexChars to uppercase if X format is used*/
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

/**
 * PrintfSpecifierParser - Parses format arguments for
 * printf function and prints them appropriately
 *
 * @countPtr: The number to format
 * @i: The index of the character in format currently
 *  being handled by printf
 * @format: The format string being used by printf
 * @arguments: The va_list of arguments in printf
 * @base: The number base
 * @sign: The number sign
 * @length: The length state of printf for the next arg
 * @hexUpper: The case of hex chars
 *
 * Return: the number of characters in the value
*/
void PrintfSpecifierParser(int *countPtr, uint16_t i, const char *format,
	va_list arguments, uint8_t base, bool sign,
	 PrintfLengthState length, bool hexUpper)
{
	switch (format[i])
	{
		case 'c':
			*countPtr += Putchar((va_arg(arguments, int)));
			break;
		case 's':
			*countPtr += Puts(va_arg(arguments, char*));
			break;
		case 'r':
			*countPtr += PutsReverse(va_arg(arguments, char *));
			break;
		case 'R':
			*countPtr += PutsRot13(va_arg(arguments, char *));
			break;
		case 'S':
			*countPtr += PutsCustom(va_arg(arguments, char *));
			break;
		case '%':
			*countPtr += Putchar('%');
			break;
		case 'b':
			*countPtr += DecimalToBinary(va_arg(arguments, uint64_t));
			break;
		case 'd':
		case 'i':
			base = 10, sign = true;
			*countPtr += PrintfNum(va_arg(arguments, int32_t), length, sign, base, hexUpper);
			break;
		case 'u':
			base = 10, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, uint64_t), length, sign, base, hexUpper);
			break;
		case 'x':
			base = 16, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, int64_t), length, sign, base, hexUpper);
			break;
		case 'X':
			base = 16, sign = false, hexUpper = true;
			*countPtr += PrintfNum(va_arg(arguments, int64_t), length, sign, base, hexUpper);
			break;
		case 'p':
			*countPtr += Puts("0x");
			base = 16, sign = false, length = LEN_LONG_LONG;
			*countPtr += PrintfNum(va_arg(arguments, uint64_t), length, sign, base, hexUpper);
			break;
		case 'o':
			base = 8, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, int64_t), length, sign, base, hexUpper);
			break;
		case '+':
		case '-':
		case ' ':
		case '#':
		case '0':
			*countPtr += PrintfFlags(format[i], arguments);
			break;
		default:
			*countPtr += Putchar(format[i - 1]);
			*countPtr += Putchar(format[i]);
			break;
	}
}




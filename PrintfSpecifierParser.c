#include "_printf.h"

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
	uint64_t nextArg = 0;

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
			*countPtr += PrintfNum(va_arg(arguments, uint64_t),
									length, sign, base, hexUpper);
			break;
		case 'u':
			base = 10, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, uint64_t),
									length, sign, base, hexUpper);
			break;
		case 'x':
			base = 16, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, int64_t),
									length, sign, base, hexUpper);
			break;
		case 'X':
			base = 16, sign = false, hexUpper = true;
			*countPtr += PrintfNum(va_arg(arguments, int64_t),
									length, sign, base, hexUpper);
			break;
		case 'p':
			nextArg = va_arg(arguments, uint64_t);
			if (!nextArg)
			{
				*countPtr += Puts("(nil)");
				break;
			}
			*countPtr += Puts("0x");
			base = 16, sign = false, length = LEN_LONG_LONG;
			*countPtr += PrintfNum(nextArg,
									length, sign, base, hexUpper);
			break;
		case 'o':
			base = 8, sign = false;
			*countPtr += PrintfNum(va_arg(arguments, int64_t),
									length, sign, base, hexUpper);
			break;
		default:
			if (length != LEN_DEFAULT)
			{
				*countPtr += Putchar(format[i - 2]);
				*countPtr += Putchar(format[i]);
				break;
			}
			*countPtr += Putchar(format[i - 1]);
			*countPtr += Putchar(format[i]);
			break;
	}
}


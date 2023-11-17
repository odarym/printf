#include "_printfHelpers.h"

/**
 * PrintfSpecifierParser - Parses statePtr->formatString statePtr->args for
 * printf function and prints them appropriately
 *
 * @statePtr->count: The number to statePtr->formatString
 * @*(statePtr->indexPtr): The index of the character in statePtr->formatString currently
 *  being handled by printf
 * @statePtr->formatString: The statePtr->formatString string being used by printf
 * @statePtr->args: The va_list of statePtr->args in printf
 * @statePtr->radix: The number statePtr->radix
 * @sign: The number sign
 * @length: The length state of printf for the next arg
 * @hexUpper: The case of hex chars
 *
 * Return: the number of characters in the value
*/
void PrintfSpecifierParser(PrintfStateHolderStruct_t *statePtr)
{
	switch (statePtr->formatString[*(statePtr->indexPtr)])
	{
		case 'c':
			*statePtr->count += Putchar((va_arg(statePtr->args, int)));
			break;
		case 's':
			*statePtr->count += Puts(va_arg(statePtr->args, char*));
			break;
		case 'r':
			*statePtr->count += PutsReverse(va_arg(statePtr->args, char *));
			break;
		case 'R':
			*statePtr->count += PutsRot13(va_arg(statePtr->args, char *));
			break;
		case 'S':
			*statePtr->count += PutsCustom(va_arg(statePtr->args, char *));
			break;
		case '%':
			*statePtr->count += Putchar('%');
			break;
		case 'b':
			*statePtr->count += DecimalToBinary(va_arg(statePtr->args, uint64_t));
			break;
		case 'd':
		case 'i':
			statePtr->radix = 10, statePtr->sign = true;
			*statePtr->count += PrintfNum(statePtr);
			break;
		case 'u':
			statePtr->radix = 10, statePtr->sign = false;
			*statePtr->count += PrintfNum(statePtr);
			break;
		case 'x':
			statePtr->radix = 16, statePtr->sign = false;
			*statePtr->count += PrintfNum(statePtr);
			break;
		case 'X':
			statePtr->radix = 16, statePtr->sign = false, statePtr->hexUpper = true;
			*statePtr->count += PrintfNum(statePtr);
			break;
		case 'p':
			statePtr->nextArgument = va_arg(statePtr->args, uint64_t);
			if (!statePtr->nextArgument)
			{
				*statePtr->count += Puts("(nil)");
				break;
			}
			*statePtr->count += Puts("0x");
			statePtr->radix = 16, statePtr->sign = false, statePtr->length = LEN_LONG_LONG;
			*statePtr->count += PrintfNum(statePtr);
			break;
		case 'o':
			statePtr->radix = 8, statePtr->sign = false;
			*statePtr->count += PrintfNum(statePtr);
			break;
		default:
			if (statePtr->length != LEN_DEFAULT)
			{
				*statePtr->count += Putchar(statePtr->formatString[*(statePtr->indexPtr) - 2]);
				*statePtr->count += Putchar(statePtr->formatString[*(statePtr->indexPtr)]);
				break;
			}
			*statePtr->count += Putchar(statePtr->formatString[*(statePtr->indexPtr) - 1]);
			*statePtr->count += Putchar(statePtr->formatString[*(statePtr->indexPtr)]);
			break;
	}
}


#include "PrintfHelpers.h"


/**
 * _printf - Print a formatted string
 *
 * @format: The string specifying the format
 *
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	PrintfStateHolderStruct_t *printfStatePtr = malloc(sizeof(PrintfStateHolderStruct_t));
	int i = 0, count = 0;

	if ((!printfStatePtr) || (!format)) /*NULL format string or malloc return*/
		return (-1);
	ResetPrintfState(printfStatePtr);
	printfStatePtr->widthBuf[18] = '\0';
	printfStatePtr->precisionBuf[18] = '\0';
	printfStatePtr->formatString = format;
	printfStatePtr->indexPtr = &i;
	printfStatePtr->count = &count;

	va_copy(printfStatePtr->argsCopy, printfStatePtr->args);
	va_start(printfStatePtr->args, format);
	for (; format[i]; i++)
	{
		switch (printfStatePtr->state)
		{
			case NORMAL:
				switch (format[i])
				{
					case '%':
						printfStatePtr->state = FLAG;
						break;
					default:
						count += Putchar(format[i]);
						break;
				}
				break;
			case FLAG:
				PrintfFlags(printfStatePtr);
				break;
			case WIDTH:
				PrintfWidth(printfStatePtr);
				break;
			case PRECISION:
				switch (format[i])
				{
					case '*':
						printfStatePtr->precision = va_arg(printfStatePtr->args, int);
						break;
					default:
						i--;
						printfStatePtr->state = LENGTH;
				}
				break;
			case LENGTH:
				switch (format[i])
				{
					case 'h':
						printfStatePtr->state = LENGTH;
						printfStatePtr->length = LEN_SHORT, printfStatePtr->state = SHORT;
						break;
					case 'l':
						printfStatePtr->state = LENGTH;
						printfStatePtr->length =  LEN_LONG;
						break;
					default:
						i--;
						printfStatePtr->state = SPEC;
				}
				break;
			case SHORT:
				if (format[i] == 'h')
					printfStatePtr->length = LEN_SHORT_SHORT, printfStatePtr->state = SPEC;
				else
					goto PRINTF_STATE_SPEC_;
				break;
			case LONG:
				if (format[i] == 'l')
					printfStatePtr->length = LEN_LONG_LONG, printfStatePtr->state = SPEC;
				else
					goto PRINTF_STATE_SPEC_;
				break;
			case SPEC:
PRINTF_STATE_SPEC_:
				PrintfSpecifierParser(printfStatePtr);
				/*Reset state to NORMAL*/
				ResetPrintfState(printfStatePtr);
				break;
		}
	}
	va_end(printfStatePtr->args);

	if ((format[i - 1] == '%') && (format[i - 3]))
		count = -1;

	free(printfStatePtr);
	return (count);
}

/**
 * ResetPrintfState - Reset the printf states to normal mode
 *
 * @statePtr: Pointer to the structure with printf's current states
*/
void ResetPrintfState(PrintfStateHolderStruct_t *statePtr)
{
	statePtr->state = NORMAL;
	statePtr->length = LEN_DEFAULT;
	statePtr->radix = BASE_DECIMAL;
	statePtr->hexUpper = false;
	statePtr->sign = false;
	statePtr->printSignAlways = false;
	statePtr->width = 0;
	statePtr->widthBuf[31] = '\0';
	statePtr->precision = 0;
	statePtr->precisionBuf[31] = '\0';
	statePtr->flags = FLAG_NONE;
}





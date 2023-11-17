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
	PrintfStateHolderStruct_t *printfStatePtr = malloc (sizeof(PrintfStateHolderStruct_t));
	int i = 0, j = 0, count = 0;

	if (!printfStatePtr) /*malloc failed*/
		return (-1);


	ResetPrintfState(printfStatePtr);
	printfStatePtr->widthBuf[31] = '\0';
	printfStatePtr->precisionBuf[31] = '\0';
	printfStatePtr->flags = FLAG_NONE;
	printfStatePtr->formatString = format;
	printfStatePtr->indexPtr = &i;
	printfStatePtr->count = &count;
	va_copy(printfStatePtr->argsCopy, printfStatePtr->args);

	if (!format) /*Check the validity of the format string*/
		return (-1);

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
				switch (format[i])
				{
					case '+':
						printfStatePtr->printSignAlways = true;
						printfStatePtr->flags = FLAG_PLUS;
						break;
					case '-':
						printfStatePtr->flags = FLAG_MINUS;
						goto PRINTF_STATE_SPEC_;
					case ' ':
						printfStatePtr->flags = FLAG_SPACE;
						break;
					case '#':
						if ((format[i + 1] == 'o') && (va_arg(printfStatePtr->argsCopy, uint64_t)))
							count += Putchar('0');
						if ((format[i + 1] == 'x') && (va_arg(printfStatePtr->argsCopy, uint64_t)))
							count += Puts("0x");
						if ((format[i + 1] == 'X') && (va_arg(printfStatePtr->argsCopy, uint64_t)))
							count += Puts("0X");
						printfStatePtr->flags = FLAG_HASH;
						break;
					case '0':
						printfStatePtr->flags = FLAG_ZERO;
						goto PRINTF_STATE_SPEC_;
				default:
					goto PRINTF_STATE_WIDTH_;
				}
				break;
			case WIDTH:
PRINTF_STATE_WIDTH_:
				switch (format[i])
				{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						j = 0;
						while ((format[i] >= '0') && (format[i] <= '9'))
						{
							printfStatePtr->widthBuf[j++] = format[i++];
						}
						printfStatePtr->widthBuf[j] = '\0';
						printfStatePtr->width = atoi(printfStatePtr->widthBuf);
						goto PRINTF_STATE_SPEC_;
						break;
					case '*':
						printfStatePtr->width = va_arg(printfStatePtr->args, int);
						break;
				default:
					goto PRINTF_STATE_PRECISION_;
				}
				break;
			case PRECISION:
PRINTF_STATE_PRECISION_:
				switch (format[i])
				{
					case '*':
						printfStatePtr->width = va_arg(printfStatePtr->args, int);
						break;
					default:
						goto PRINTF_STATE_LEN_;
				}
				break;
			case LENGTH:
PRINTF_STATE_LEN_:
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
						goto PRINTF_STATE_SPEC_;
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





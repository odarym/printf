#include "_printfHelpers.h"


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


	printfStatePtr->state = NORMAL, printfStatePtr->length = LEN_DEFAULT;
	printfStatePtr->radix = 10;
	printfStatePtr->hexUpper = false,
	printfStatePtr->sign = false, printfStatePtr->printSignAlways = false,
	printfStatePtr->indexPtr = &i;
	printfStatePtr->width = 0;
	printfStatePtr->widthBuf[31] = '\0';
	printfStatePtr->precision = 0;
	printfStatePtr->precisionBuf[31] = '\0';
	printfStatePtr->formatString = format;
	printfStatePtr->count = &count;
	printfStatePtr->flags = FLAG_NONE;

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
						i++;
						goto PRINTF_STATE_SPEC_;
					case '#':
						printfStatePtr->flags = FLAG_HASH;
						goto PRINTF_STATE_SPEC_;
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
				printfStatePtr->state = NORMAL;
				printfStatePtr->length = LEN_DEFAULT;
				printfStatePtr->sign = false;
				printfStatePtr->hexUpper = false;
				printfStatePtr->printSignAlways = false;
				printfStatePtr->width = 0;
				printfStatePtr->precision = 0;
				printfStatePtr->radix = 10;
				printfStatePtr->flags = FLAG_NONE;
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
	if (currentStatePtr->width > 0)
	{
		while (currentStatePtr->width--)
		{
			Putchar(' ');
		}
	}

	/*Place sign*/
	if (currentStatePtr->sign && numSign < 0 && !currentStatePtr->printSignAlways)
		buffer[i++] = '-';
	else if (currentStatePtr->printSignAlways)
		count += Putchar('+');
	else if ((currentStatePtr->flags == FLAG_SPACE))
		count += Putchar(' ');

	while (--i > -1)
		count += Putchar(buffer[i]);

	return (count);
}





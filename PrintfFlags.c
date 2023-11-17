#include "PrintfHelpers.h"


/**
 * PrintfFlags - Handle flag specifiers
 *
 * thisState - current printf state
 *
 * Return: 0
 */
int PrintfFlags(PrintfStateHolderStruct_t *thisState)
{
	switch (thisState->formatString[(*(thisState->indexPtr))])
	{
		case '+':
			thisState->printSignAlways = true;
			thisState->flags = FLAG_PLUS;
			break;
		case '-':
			thisSta te->flags = FLAG_MINUS;
			/*Don't consume character instead switch to specifier state*/
			/*Basically i-- inside printf*/
			(*(thisState->indexPtr) = (*(thisState->indexPtr)) - 1);
			thisState->state = SPEC;
			break;
		case ' ':
			thisState->flags = FLAG_SPACE;
			break;
		case '#':
			if ((thisState->formatString[(*(thisState->indexPtr)) + 1] == 'o')
					&& (va_arg(thisState->argsCopy, uint64_t)))
				*(thisState->count) += Putchar('0');
			if ((thisState->formatString[(*(thisState->indexPtr)) + 1] == 'x')
					&& (va_arg(thisState->argsCopy, uint64_t)))
				*(thisState->count) += Puts("0x");
			if ((thisState->formatString[(*(thisState->indexPtr)) + 1] == 'X')
					&& (va_arg(thisState->argsCopy, uint64_t)))
				thisState->count += Puts("0X");
			thisState->flags = FLAG_HASH;
			break;
		case '0':
			thisState->flags = FLAG_ZERO;

			(*(thisState->indexPtr) = (*(thisState->indexPtr)) - 1);
			thisState->state = WIDTH;
			break;
	default:
		(*(thisState->indexPtr) = (*(thisState->indexPtr)) - 1);
		thisState->state = WIDTH;
		break;
	}
	return (0);
}

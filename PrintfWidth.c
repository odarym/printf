#include "PrintfHelpers.h"


bool IsNumChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return true;

	return false;
}

void PrintfWidth(PrintfStateHolderStruct_t *thisState)
{
	int j = 0;
	switch (thisState->formatString[(*(thisState->indexPtr))])
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
			while ((thisState->formatString[(*(thisState->indexPtr))] >= '0')
					&& (thisState->formatString[(*(thisState->indexPtr))] <= '9'))
			{
				thisState->widthBuf[j++] = thisState->formatString[(*(thisState->indexPtr))++];
			}
			thisState->widthBuf[j] = '\0';
			thisState->width = atol(thisState->widthBuf);

			(*(thisState->indexPtr)) = (*(thisState->indexPtr)) - 1; 
			thisState->state = SPEC;
			break;
		case '*':
			thisState->width = va_arg(thisState->args, int);
			break;
	default:
			(*(thisState->indexPtr)) = (*(thisState->indexPtr)) - 1; 
			thisState->state = PRECISION;
	}
}
#ifndef _PRINTF_HELPERS_H
#define _PRINTF_HELPERS_H

#include "_printf.h"


struct HexChars
{
	const char *hexCharsLower;
	const char *hexCharsUpper;
};
typedef struct HexChars HexChars_t;

struct PrintfStateHolderStruct
{
	PrintfState state;
	PrintfLengthState length;
	PrintfFlagsState flags;

	int *count;
	int *indexPtr;

	int width;
	char widthBuf[20];
	int precision;
	char precisionBuf[20];

	uint64_t nextArgument;
	int8_t numSign;
	uint8_t radix;
	bool hexUpper;
	bool sign;
	bool printSignAlways;

	va_list args;
	va_list argsCopy;

	const char *formatString;

	HexChars_t numChars;
};
typedef struct PrintfStateHolderStruct PrintfStateHolderStruct_t;

uint8_t PrintfNum(PrintfStateHolderStruct_t *currentStatePtr);
void PrintfSpecifierParser(PrintfStateHolderStruct_t *statePtr);
int PrintfFlags(char flag, va_list arguments);
void ResetPrintfState(PrintfStateHolderStruct_t *statePtr);


#endif


#ifndef PRINTF_HELPERS_H
#define PRINTF_HELPERS_H

#include "_printf.h"


typedef struct __attribute__ ((__packed__)) HexChars
{
	const char *hexCharsLower;
	const char *hexCharsUpper;
} HexChars_t;

typedef struct PrintfStateHolderStruct
{
	PrintfState state;
	PrintfLengthState length;
	PrintfFlagsState flags;
	Radices radix;

	int *count;
	int *indexPtr;

	int width;
	char widthBuf[32];

	int precision;
	char precisionBuf[32];

	uint64_t nextArgument;
	int8_t numSign;
	bool hexUpper;
	bool sign;
	bool printSignAlways;

	va_list args;
	va_list argsCopy;
	
	const char *formatString;

	HexChars_t numChars;
} PrintfStateHolderStruct_t;



uint8_t PrintfNum(PrintfStateHolderStruct_t *currentStatePtr);
void PrintfSpecifierParser(PrintfStateHolderStruct_t *statePtr);
int PrintfFlags(char flag, va_list arguments);
void ResetPrintfState(PrintfStateHolderStruct_t *printfState);
/* int PrintfFlags(PrintfFlagsState flag, va_list arguments); */


#endif


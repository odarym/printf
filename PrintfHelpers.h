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
	/*Enums with different state values for printf*/
	PrintfState state;
	PrintfLengthState length;
	PrintfFlagsState flags;
	Radices radix;

	/*Total number of characters printd so far*/
	int *count;
	/*The loop index for format*/
	int *indexPtr;

	signed long width;
	char widthBuf[19];
	signed long precision;
	char precisionBuf[19];

	uint64_t nextArgument;
	int8_t numSign;
	bool hexUpper;
	bool sign;
	bool printSignAlways;
	/*A list of the variadic arguments and a copy where needed*/
	va_list args;
	va_list argsCopy;
	/*The format string in _printf*/
	const char *formatString;

	HexChars_t numChars;
} PrintfStateHolderStruct_t;



uint8_t PrintfNum(PrintfStateHolderStruct_t *currentStatePtr);
void PrintfSpecifierParser(PrintfStateHolderStruct_t *statePtr);
void ResetPrintfState(PrintfStateHolderStruct_t *printfState);
int PrintfFlags(PrintfStateHolderStruct_t *);
void PrintfWidth(PrintfStateHolderStruct_t *);
/* int PrintfFlags(PrintfFlagsState flag, va_list arguments); */


#endif


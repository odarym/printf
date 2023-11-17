#ifndef _PRINTF_HELPERS_H
#define _PRINTF_HELPERS_H

#include "_printf.h"


struct HexChars
{
	const char* hexCharsLower;
	const char* hexCharsUpper;
};
typedef struct HexChars HexChars_t;

struct PrintfStateHolderStruct
{
	PrintfState state;
	PrintfLengthState length;
	PrintfFlagsState flags;
	/* PrintfFlagsState flags; */
	int *count;

	uint64_t nextArgument;
	int8_t numSign;
	uint8_t radix;
	bool hexUpper;
	bool sign;
	bool printSignAlways;

	va_list args;
	const char* formatString;

	HexChars_t numChars;

	int *indexPtr;
	int width;
	char widthBuf[32];
};
typedef struct PrintfStateHolderStruct PrintfStateHolderStruct_t;
/* 
uint8_t PrintfNum(uint64_t arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper, bool printSignAlways);

void PrintfSpecifierParser(int *countPtr, uint16_t i, const char *specifier,
	va_list arguments, uint8_t base, bool sign,
	PrintfLengthState length, bool hexUpper, bool printSignAlways);
 */

uint8_t PrintfNum(PrintfStateHolderStruct_t *currentStatePtr);
void PrintfSpecifierParser(PrintfStateHolderStruct_t *statePtr);
/* int PrintfFlags(PrintfFlagsState flag, va_list arguments); */


#endif


#include "main.h"

typedef enum
{
	NORMAL = 0, LENGTH, SHORT, LONG, SPEC
} PrintfState;

typedef enum
{
	LEN_DEFAULT = 0, LEN_SHORT_SHORT, LEN_SHORT, LEN_LONG, LEN_LONG_LONG
} PrintfLengthState;

uint8_t PrintfNum(uint64_t arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper);
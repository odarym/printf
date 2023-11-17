#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>


int Putchar(char ch);
int Puts(char *string);
int _printf(const char *format, ...);
void DecToHex(char *outBuffer, uint64_t number);
int DecimalToBinary(uint32_t decimalNum);
int PutsCustom(char *string);
int PutsReverse(char *string);
int PutsRot13(char *string);



#endif


#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 *
 * Desc: Header file containing declartions for functions
 * and all standard library headers that will be used in the project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>


int Putchar(char ch);
int Puts(char *string);
int _printf(const char *format, ...);
char *ConvertBase(uint64_t number, uint8_t radix);
int DecimalToBinary(uint32_t decimalNum);
int PutsCustom(char *string);
int PrintfFlags(char flag, va_list arguments);
int PutsReverse(char *string);
int PutsRot13(char *string);



#endif


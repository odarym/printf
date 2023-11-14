#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 *
 * Desc: Header file containing declartions for functions
 * and all standard library headers that will be used in the project
*/

/* Macro that checks if varidic argument list is empty */
/*#define IsEmpty(...) ( sizeof( (char[]){#__VA_ARGS__} ) == 1 )*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>


void Putchar(char ch);
int Puts(char *string);
int _printf(const char *format, ...);
int DecimalToBinary(int decimalNum);
int PutsCustom(char *string);
<<<<<<< HEAD
int PrintfFlags(char flag, char specifier);
int PutsReverse(char *string);
=======
int PrintfFlags(char flag, va_list arguments);
>>>>>>> 35431d7b4734563166b7f0a4cd430a7a56678e84


#endif
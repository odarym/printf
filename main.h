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


void _putchar(char ch);
int _puts(char *string);
int _printf(const char *format, ...);


#endif



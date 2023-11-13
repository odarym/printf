#include <stdio.h>

int flagSpace(int number)

{
    int a = 1234;
    double b = 1234.0;

    putchar("%+2d/n %-2d/n % 2d/n", a );
    putchar("%#g/n", b );

    return(0);
}
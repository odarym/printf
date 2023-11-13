#include <stdio.h>

int flagSpace(int number)

{
    int a = 1234;/*initialize number a*/
    double b = 1234.0;/*initialize b*/

    putchar("%+2d/n %-2d/n % 2d/n", a);
    putchar("%#g/n", b);
}
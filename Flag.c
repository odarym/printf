#include <stdio.h>

int flagSpace(int numberSin, int numberDouble)

{
    int numberSin = 0;
    {
      putchar("%2d/n", numberSin );
      putchar("%-2d/n", numberSin );
      putchar("% d/n", numberSin );  

    }

    int numberDouble = 456;
    {
        putchar("%#g/n", numberDouble);
    }
    return (0);
}
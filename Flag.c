#include <stdio.h>

int flagSpace(int numSin, int numDouble)

{
    int numberSin = 0;
    {
      putchar("%2d/n", numSin );
      putchar("%-2d/n", numSin );
      putchar("% d/n", numSin );  

    }

    int numDouble = 456;
    {
        putchar("%#g/n", numDouble );
    }
    return (0);
}
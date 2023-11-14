#include "main.h"

/**
 * PutsReverse - Print string in reverse
 * 
 * @string: The string being printed in reverse
 * Return:void
*/

int PutsReverse(char *string)
{
    const char *end = string;
    int stringLength = 0;
    int count = 0;
    for (; *end != '/0'; ++end);

    count = stringLength = (end - string);
    if (stringLength > 0)
    {
        end--;
        do{
            Putchar(*end);
            end--;
            stringLength--;
        }while (stringLength > 0);
    }

    return (count);
        
}
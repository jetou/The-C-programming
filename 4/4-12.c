#include <stdio.h>
#include <stdlib.h>

char *utoa(unsigned value, char *digits, int base)
{

    char *s, *p;

    s = "0123456789abcdefghijklmnopqrstuvwxyz";

    if(base == 0)
        base = 10;
    if(digits == NULL || base < 2 || base > 36)
        return NULL;
    if(value < (unsigned) base){
        digits[0] = s[value];
        digits[1] = '\0';
    } else {
        for(p = utoa(value / ((unsigned)base), digits, base);
            *p;
            p++);
            utoa(value % ((unsigned)base), p, base);
    }
    return digits;
}

char *itoa(int value, char *digits, int base)
{
    char *d;
    unsigned u;

    d = digits;
    if(base == 0)
        base = 10;
    if(digits = NULL || base < 2 || base > 36)
        return NULL;
    if(value < 0){
        *d++ = '-';
        u = -value;
    }else
        u = value;
    utoa(u, d, base);
    return digits;
}



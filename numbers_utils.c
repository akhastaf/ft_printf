#include "ft_printf.h"

int     count_int(unsigned int n)
{
    unsigned int i;

    i = 0;
    while (n >= 10)
    {
        i++;
        n = n/10;
    }
    if (n <= 9)
        i++;
    return (i);
}
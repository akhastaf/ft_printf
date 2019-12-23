#include "ft_printf.h"

void    ft_putnstr(char *s, int n)
{
    int i;

    i = 0;
    while (i < n)
        write(1, &s[i++], 1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
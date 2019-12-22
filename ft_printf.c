#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int     i;
    va_list ap;
    t_f     f;

    i = 0;

    va_start(ap, format);
    f.f = (char *)format;
    f.l = 0;
     while (*f.f)
     {
        if (*f.f == '%' && *(f.f + 1) != '%')
        {
            f.f++;
            format_handler(&ap, &f);
        }
        else
        {
            write(1, f.f, 1);
            f.f++;
            f.l++;
        }
     }
     va_end(ap);
    return f.l;
}

void    format_handler(va_list *ap, t_f *f)
{
    flags_reset(&(*f));
    flags_fill(ap, &(*f));
    if (*(f->f) == 'd' || *(f->f) == 'i') 
        print_int(ap, &(*f));
     /*else if (*f->f == 'x' || *f->f == 'X')
        (*f->f == 'x' ? print_hex(&ap, &f, 0) : print_hex(&ap, &f, 1)); */  
    else if (*(f->f) == 'u')
        print_uint(ap, &(*f));
    /*else if (*f->f == 'p')
        print_pointer(&ap, &f);*/
    else if (*f->f == 's')
        print_str(ap, &(*f));
    else if (*f->f == 'c')
        print_char(ap, &(*f));
     
    f->f++;
}
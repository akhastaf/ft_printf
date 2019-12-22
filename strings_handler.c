#include "ft_printf.h"

void    print_str(va_list *ap, t_f *f)
{
    char *s;

    s = va_arg(*ap, char*);
    if (!s)
        s = "(null)";
    flags_string(&(*f), s);
    print_s_or_z(f->ls, ' ');
    f->lv = ((f->lv >= 0 && f->is_p) ? f->lv : ft_strlen(s));
    ft_putnstr(s, f->lv);
    print_s_or_z(f->rs, ' ');
    f->l += f->lv + f->rs + f->ls; 
}

void    print_char(va_list *ap, t_f *f)
{
    char c;

    c = va_arg(*ap, int);
    flags_char(&(*f));
    print_s_or_z(f->ls, ' ');
    ft_putchar(c);
    print_s_or_z(f->rs, ' ');
    f->l += f->rs + f->ls + 1;
}

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
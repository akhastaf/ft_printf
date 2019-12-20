#include "ft_printf.h"

void    flags_number(t_f *f, int n)
{
    if (f->p > 0 && f->p > f->lv)
    {
        if (n < 0)
        {
            f->lz = f->p - f->lv + 1;
            f->l++;
        }
        else
            f->lz = f->p - f->lv;
        f->lv += f->p - f->lv;
    }
    if (f->z && abs(f->z) > f->lv && f->p > 0)
    {
        if (f->z > 0)
            f->ls = f->z - f->lv;
        else
            f->rs = abs(f->z) - f->lv;
        f->lv += abs(f->z) - f->lv;
    }
    if (f->z > 0 && f->z > f->lv)
    {
        f->lz += f->z - f->lv;
        f->lv += f->z - f->lv;
    }
    if (f->w && abs(f->w) > f->lv)
    {
        if (f->p > 0 && n < 0)
        {
            f->lv++;
            f->l--;
        }
        if (f->w > 0)
            f->ls += f->w - f->lv;
        else
            f->rs += abs(f->w) - f->lv;
        f->lv += abs(f->w) - f->lv;
    }
    // if (f->is_p && f->p == 0 && f->w > 0)
    //      f->ls = f->w;
    // else if (f->w < 0)
    //     f->rs = abs(f->w);
    
}

void    flags_fill(va_list *ap, t_f *f)
{
    int neg;

    neg = 1;
    if (*(f->f) == '0')
    {
        f->f++;
        if (*(f->f) == '*')
        {
            f->z = va_arg(*ap, int);
            f->f++;
        }
        else
            f->z = ft_atoi(f->f);
    }
    if (*(f->f) == '-')
    {
        neg = -1;
    }
    while (*(f->f) == '-' && !ft_is_format(*f->f))
        (f->f)++;
    if (*(f->f) == '*')
        f->w = va_arg(*ap, int);
    else if (!ft_is_format(*f->f) && (*(f->f) != '.'))
        f->w = ft_atoi((*f).f) * neg;
    while (*(f->f) != '.' && !ft_is_format(*f->f))
        f->f++;
    f->is_p = (*(f->f) == '.' ? 1 : 0);
    if (*(f->f + 1) == '*' && *(f->f ) == '.')
        f->p = va_arg(*ap, int);
    else if (*(f->f ) == '.')
        f->p = ft_atoi(f->f + 1);
    while (!ft_is_format(*f->f))
        f->f++;
}

void    flags_reset(t_f *f)
{
    (*f).z = 0;
    (*f).w = 0;
    (*f).p = 0;
    (*f).is_p = 0;
    (*f).ls = 0;
    (*f).lz = 0;
    (*f).rs = 0;
    (*f).lv = 0;
}

int     ft_is_format(char f)
{
   if (f == 'd' || f == 'i' || f == 'x' || f == 'X' || f == 'p' || f == 's' || f == 'c')
        return (1);
    return (0);
}
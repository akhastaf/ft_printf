/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:49:01 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/23 15:49:03 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    print_percent(t_f *f)
{

    flags_percent(&(*f));
    print_s_or_z(f->ls, ' ');
    ft_putchar('%');
    print_s_or_z(f->rs, ' ');
    f->l += f->rs + f->ls + 1;
}

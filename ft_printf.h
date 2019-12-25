/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:51:25 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/25 21:23:52 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
typedef struct		s_flags
{
    int     z;
    int     w;
    int     p;
    int     is_p;
    int     l;
    int     lv;
    int     ls;
    int     lz;
    int     rs;
    char    *f;
}					t_f;
# define abs(value) (value < 0 ? -value : value)
int     ft_printf(const char *format, ...);
void    format_handler(va_list *ap, t_f *f);
int     count_int(unsigned int n);
int     count_hex(unsigned long n, int is_p);
void    ft_putnbr(unsigned int n);
void    ft_puthex(unsigned long n, int maj);
void    flags_number(t_f *f, unsigned long n, int neg);
void    h_flags_number(t_f *f, int neg);
void    flags_string(t_f *f, char *s);
void    flags_char(t_f *f);
void    flags_percent(t_f *f);
void    flags_fill(va_list *ap, t_f *f);
void    flags_reset(t_f *f);
void    get_zero(va_list *ap, t_f *f);
void    get_width(va_list *ap, t_f *f);
void    get_point(va_list *ap, t_f *f);
void    print_int(va_list *ap, t_f *f);
void	print_uint(va_list *ap, t_f *f);
void	print_hex(va_list *ap, t_f *f, int maj);
void	print_pointer(va_list *ap, t_f *f);
void    print_str(va_list *ap, t_f *f);
void    print_char(va_list *ap, t_f *f);
void    print_percent(t_f *f);
void    ft_putnstr(char *s, int n);
void    ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	print_s_or_z(int n, char c);
int     ft_is_format(char f);
#endif

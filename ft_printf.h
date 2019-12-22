#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
typedef struct		s_flags
{
    int     z;      // zero 
    int     w;      // width  
    int     p;      // point
    int     is_p;   // point exit
    int     l;      // lenght
    int     lv;     // lenght of value
    int     ls;     // left sapces
    int     lz;     // left zeros
    int     rs;     // right sapces
    char    *f;     // format
}					t_f;
# define abs(value) (value < 0 ? -value : value)

int     ft_printf(const char *format, ...);
void    format_handler(va_list *ap, t_f *f);

// numbers_utils.c
int     count_int(unsigned int n);
int     count_hex(unsigned int n);
void    ft_putnbr(unsigned int n);
void    ft_puthex(unsigned int n, int maj);


// flags_handler.c
void    flags_number(t_f *f, unsigned int n, int neg);
void    flags_fill(va_list *ap, t_f *f);
void    flags_reset(t_f *f);
void    flags_string(t_f *f, char *s);
void    flags_char(t_f *f);

// numbers_handler.c
void    print_int(va_list *ap, t_f *f);
void	print_uint(va_list *ap, t_f *f);

// strnigs_handler.c
void    print_str(va_list *ap, t_f *f);
void    ft_putnstr(char *s, int n);
void    print_char(va_list *ap, t_f *f);
void    ft_putchar(char c);

// ft_printf_utils.c
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	print_s_or_z(int n, char c);
int     ft_is_format(char f);
void	print_hex(va_list *ap, t_f *f, int maj);


#endif
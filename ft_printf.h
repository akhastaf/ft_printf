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
int     count_int(unsigned int n);
// flags_handler.c
void    flags_number(t_f *f, int n);
void    flags_fill(va_list *ap, t_f *f);
void    flags_reset(t_f *f);

// numbers_handler.c
void     ft_putnbr(unsigned int n);
void    print_int(va_list *ap, t_f *f);

// ft_printf_utils.c
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	print_s_or_z(int n, char c);
int     ft_is_format(char f);

#endif
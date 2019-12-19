#include "ft_printf.h"

void    print_int(va_list *ap, t_f *f)
{
    int n;
    
    n = va_arg(*ap, int);
    f->lv = count_int(abs(n));
	if (n < 0)
		f->lv++;
    flags_number(&(*f), n);
    print_s_or_z(f->ls, ' ');
	if (n < 0)
		write(1, "-", 1);
	print_s_or_z(f->lz, '0');
    ft_putnbr(abs(n));
    print_s_or_z(f->rs, ' ');
    f->l += f->lv;
}


void     ft_putnbr(unsigned int n)
{
    char			c;

	if (n <= 9)
	{
		c = '0' + n;
		write(1, &c, 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}
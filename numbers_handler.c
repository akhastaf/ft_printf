/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:48:45 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/25 21:14:36 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(va_list *ap, t_f *f)
{
	int n;

	n = va_arg(*ap, int);
	f->lv = count_int(abs(n)) + (n < 0 ? 1 : 0);
	if (f->is_p && !f->p && !n)
		f->lv--;
	flags_number(&(*f), abs(n), n < 0 ? -1 : 1);
	print_s_or_z(f->ls, ' ');
	if (n < 0)
		write(1, "-", 1);
	print_s_or_z(f->lz, '0');
	if (!(f->is_p && f->p == 0 && n == 0))
		ft_putnbr(abs(n));
	else if (!f->w && n < 0)
		f->l--;
	print_s_or_z(f->rs, ' ');
	f->l += f->lv;
}

void	print_uint(va_list *ap, t_f *f)
{
	unsigned int n;

	n = va_arg(*ap, unsigned int);
	f->lv = count_int(n);
	if (f->is_p && !f->p && !n)
		f->lv--;
	flags_number(&(*f), n, 1);
	print_s_or_z(f->ls, ' ');
	print_s_or_z(f->lz, '0');
	if (!(f->is_p && f->p == 0 && n == 0))
		ft_putnbr(n);
	else if (!f->w && (int)n < 0)
		f->l--;
	print_s_or_z(f->rs, ' ');
	f->l += f->lv;
}

void	print_hex(va_list *ap, t_f *f, int maj)
{
	unsigned int n;

	n = va_arg(*ap, unsigned int);
	f->lv = count_hex(n, 0);
	if (f->is_p && !f->p && !n)
		f->lv--;
	flags_number(&(*f), n, 1);
	print_s_or_z(f->ls, ' ');
	print_s_or_z(f->lz, '0');
	if (!(f->is_p && f->p == 0 && n == 0))
		ft_puthex(n, maj);
	else if (!f->w && (int)n < 0)
		f->l--;
	print_s_or_z(f->rs, ' ');
	f->l += f->lv;
}

void	print_pointer(va_list *ap, t_f *f)
{
	unsigned long n;

	n = va_arg(*ap, unsigned long);
	f->lv = count_hex(n, 1) + 2 + (!n ? 1 : 0);
	if (f->is_p && !f->p && !n)
		f->lv--;
	flags_number(&(*f), n, 1);
	print_s_or_z(f->ls, ' ');
	print_s_or_z(f->lz, '0');
	ft_putnstr("0x", 2);
	if (!(f->is_p && f->p == 0 && n == 0))
		ft_puthex(n, 0);
	else if (!f->w && (int)n < 0)
		f->l--;
	print_s_or_z(f->rs, ' ');
	f->l += f->lv;
}

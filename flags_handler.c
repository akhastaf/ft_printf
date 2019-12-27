/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:48:12 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/27 16:42:14 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_number(t_f *f, unsigned long n, int neg)
{
	h_flags_number(&(*f), neg);
	if (f->z > 0 && f->z > f->lv)
	{
		f->lz += f->z - f->lv;
		f->lv += f->z - f->lv;
	}
	if (f->w && ABS(f->w) > f->lv)
	{
		if (f->w > 0)
			f->ls += f->w - f->lv;
		else
			f->rs += ABS(f->w) - f->lv;
		f->lv += ABS(f->w) - f->lv;
	}
	if (f->is_p && f->p == 0 && f->w > f->lv && n == 0)
		f->ls = f->w;
}

void	h_flags_number(t_f *f, int neg)
{
	if (f->p > 0 && f->p + (neg < 0 ? 1 : 0) > f->lv)
	{
		f->lz = f->p - f->lv + (neg < 0 ? 1 : 0);
		f->lv += f->lz;
	}
	if (f->z && ABS(f->z) > f->lv && f->is_p && f->p >= 0)
	{
		if (f->z > 0)
			f->ls = f->z - f->lv;
		else
			f->rs = ABS(f->z) - f->lv;
		f->lv += ABS(f->z) - f->lv;
	}
	if (f->z < 0 && f->is_p && f->p < 0 && ABS(f->z) > f->lv)
	{
		f->rs = ABS(f->z) - f->lv;
		f->lv += f->rs;
	}
}

void	flags_string(t_f *f, char *s)
{
	f->lv = ft_strlen(s);
	if (f->is_p && f->p < 0)
		f->lv = ft_strlen(s);
	else if (f->is_p && f->p >= 0)
		f->lv = (f->p < ft_strlen(s) ? f->p : (int)ft_strlen(s));
	if (ABS(f->w) > f->lv)
	{
		if (f->w > 0)
			f->ls = f->w - f->lv;
		else
			f->rs = ABS(f->w) - f->lv;
	}
}

void	flags_char(t_f *f)
{
	if (ABS(f->w) > f->lv)
	{
		if (f->w > 0)
			f->ls = f->w - 1;
		else
			f->rs = ABS(f->w) - 1;
	}
}

void	flags_percent(t_f *f)
{
	f->lv = 1;
	if (f->is_p && f->z < 0)
	{
		f->rs = ABS(f->z) - f->lv;
		f->lv += f->rs;
	}
	else if (f->is_p && f->z > 0)
	{
		f->lz = f->z - f->lv;
		f->lv += f->lz;
	}
	if (f->z > 0 && !f->is_p)
	{
		f->lz = f->z - 1;
		f->lv += f->lz;
	}
	if (ABS(f->w) > f->lv)
	{
		if (f->w > 0)
			f->ls = f->w - f->lv;
		else
			f->rs = ABS(f->w) - f->lv;
		f->lv += ABS(f->w) - f->lv;
	}
}

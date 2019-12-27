/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:48:30 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/27 16:40:47 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_fill(va_list *ap, t_f *f)
{
	get_zero(ap, &(*f));
	get_width(ap, &(*f));
	get_point(ap, &(*f));
}

void	flags_reset(t_f *f)
{
	(*f).z = 0;
	(*f).w = 0;
	(*f).sw = 1;
	(*f).p = 0;
	(*f).is_p = 0;
	(*f).ls = 0;
	(*f).lz = 0;
	(*f).rs = 0;
	(*f).lv = 0;
}

void	get_zero(va_list *ap, t_f *f)
{
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
}

void	get_width(va_list *ap, t_f *f)
{
	int neg;

	neg = 1;
	if (*(f->f) == '-')
		neg = -1;
	while (*(f->f) == '-' && !ft_is_format(*f->f))
		(f->f)++;
	if (*(f->f) == '*')
	{
		f->w = va_arg(*ap, int);
		if (f->w > 0)
			f->w *= neg;
	}
	else if (!ft_is_format(*f->f) && (*(f->f) != '.'))
		f->w = ft_atoi((*f).f) * neg;
	f->w *= f->sw;
}

void	get_point(va_list *ap, t_f *f)
{
	while (*(f->f) != '.' && !ft_is_format(*f->f))
		f->f++;
	f->is_p = (*(f->f) == '.' ? 1 : 0);
	if (*(f->f + 1) == '*' && *(f->f) == '.')
		f->p = va_arg(*ap, int);
	else if (*(f->f) == '.')
		f->p = ft_atoi(f->f + 1);
	while (!ft_is_format(*f->f))
		f->f++;
}

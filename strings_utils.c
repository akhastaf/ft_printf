/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:49:08 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/27 16:46:44 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
		write(1, &s[i++], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	skip_percent(t_f *f)
{
	int m;
	int z;
	int i;

	m = 0;
	z = 0;
	i = 0;
	while (!ft_is_format(f->f[i]))
	{
		if (f->f[i] == '0')
			z = 1;
		else if (f->f[i] == '-')
			m = 1;
		i++;
	}
	if (f->f[i] == '%' && m && z)
	{
		while (*f->f == '-' || *f->f == '0')
			f->f++;
		f->sw = -1;
	}
}

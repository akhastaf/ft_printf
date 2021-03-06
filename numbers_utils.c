/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:48:52 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/26 17:27:59 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_int(unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	if (n <= 9)
		i++;
	return (i);
}

int		count_hex(unsigned long n, int is_p)
{
	int i;

	i = 0;
	if (!n && !is_p)
		i++;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i + (!n ? 0 : 1));
}

void	ft_putnbr(unsigned int n)
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

void	ft_puthex(unsigned long n, int maj)
{
	char	number[20];
	int		i;

	i = 0;
	if (n == 0)
		number[i++] = '0';
	while (n >= 10)
	{
		if (n % 16 > 9)
			number[i] = n % 16 - 10 + (maj == 1 ? 'A' : 'a');
		else
			number[i] = n % 16 + '0';
		i++;
		n = n / 16;
	}
	if (n > 0 && n < 10)
	{
		number[i] = n % 16 + '0';
		i++;
	}
	number[i] = '\0';
	i--;
	while (i >= 0)
		write(1, &number[i--], 1);
}

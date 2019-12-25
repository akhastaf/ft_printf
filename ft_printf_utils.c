/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:48:01 by akhastaf          #+#    #+#             */
/*   Updated: 2019/12/25 21:09:42 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	size_t	n;

	i = 0;
	signe = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		n = n * 10 + str[i] - 48;
		if (n > 9223372036854775807)
			return ((signe > 0) ? -1 : 0);
		i++;
	}
	return ((int)(n * signe));
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_s_or_z(int n, char c)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}

int		ft_is_format(char f)
{
	if (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X'
			|| f == 'p' || f == 's' || f == 'c' || f == '%')
		return (1);
	return (0);
}

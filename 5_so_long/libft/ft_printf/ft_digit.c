/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:06:52 by femorell          #+#    #+#             */
/*   Updated: 2022/11/21 17:06:53 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_stampa(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_stampa(n / 10);
		ft_stampa(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

int	ft_digit(int n)
{
	long			i;
	int				j;

	i = n;
	j = 1;
	ft_stampa(n);
	if (i < 0)
	{
		i *= -1;
		j++;
	}
	while (i >= 10)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

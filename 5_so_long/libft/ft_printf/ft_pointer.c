/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:06:41 by femorell          #+#    #+#             */
/*   Updated: 2022/11/21 17:06:42 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prova(unsigned long int n)
{
	if (n >= 16)
	{
		prova(n / 16);
		prova(n % 16);
	}
	else
	{
		if (n > 9)
			n += 87;
		else
			n += 48;
		write(1, &n, 1);
	}
}

int	ft_pointer(unsigned long int n)
{
	unsigned long int	i;
	int					j;

	i = n;
	j = 1;
	if (i == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	prova(n);
	while (i >= 16)
	{
		i /= 16;
		j++;
	}
	return (j + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:07:07 by femorell          #+#    #+#             */
/*   Updated: 2022/11/21 17:07:08 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prova(unsigned int n)
{
	if (n >= 10)
	{
		prova(n / 10);
		prova(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

int	ft_unsigned_int(unsigned int n)
{
	long			i;
	int				j;

	i = n;
	j = 1;
	prova(n);
	while (i >= 10)
	{
		i /= 10;
		j++;
	}
	return (j);
}

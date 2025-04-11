/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:07:19 by femorell          #+#    #+#             */
/*   Updated: 2022/11/21 17:07:20 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prova(unsigned int n, char c)
{
	if (n >= 16)
	{
		prova(n / 16, c);
		prova(n % 16, c);
	}
	else if (n > 9)
	{
		if (c == 'x')
			n += 87;
		else
			n += 55;
		write(1, &n, 1);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

int	ft_hexadecimal(unsigned int n, char c)
{
	unsigned int	i;
	int				j;

	i = n;
	j = 1;
	prova(n, c);
	while (i >= 16)
	{
		i /= 16;
		j++;
	}
	return (j);
}

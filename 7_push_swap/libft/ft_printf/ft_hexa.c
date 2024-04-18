/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:14:51 by sum               #+#    #+#             */
/*   Updated: 2022/05/18 17:14:53 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long long nbr, const char *format, int *len)
{
	unsigned long long		nb;
	char					*hexa;

	nb = (unsigned int)nbr;
	if (*format == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nb < 16)
		ft_putchar(hexa[nb % 16], len);
	else if (nb >= 16)
	{
		ft_hexa(nb / 16, format, len);
		ft_hexa(nb % 16, format, len);
	}
}

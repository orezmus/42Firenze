/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:14:41 by sum               #+#    #+#             */
/*   Updated: 2022/10/21 15:14:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa_point(unsigned long a, int *len)
{
	if (a < 16)
		ft_putchar("0123456789abcdef"[a % 16], len);
	else if (a >= 16)
	{
		hexa_point(a / 16, len);
		ft_putchar("0123456789abcdef"[a % 16], len);
	}
}

void	ft_pointer(void *addr, int *len)
{
	char	*str;

	if (addr == 0)
		ft_putstr("(nil)", len);
	else
	{
		str = (char *)addr;
		ft_putstr("0x", len);
		hexa_point((unsigned long)str, len);
	}
}

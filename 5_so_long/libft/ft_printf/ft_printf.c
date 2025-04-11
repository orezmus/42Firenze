/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:53:59 by femorell          #+#    #+#             */
/*   Updated: 2022/10/26 15:58:50 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_takeinput(va_list ap, char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		print = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		print = ft_pointer(va_arg(ap, unsigned long int));
	else if (c == 'd' || c == 'i')
		print = ft_digit(va_arg(ap, int));
	else if (c == 'u')
		print = ft_unsigned_int(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		print = ft_hexadecimal(va_arg(ap, unsigned int), c);
	else if (c == '%')
	{
		write(1, "%", 1);
		print = 1;
	}
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		print;
	int		i;
	va_list	ap;

	i = 0;
	print = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print += ft_takeinput(ap, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			print += 1;
		}
		i++;
	}
	va_end(ap);
	return (print);
}

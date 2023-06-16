/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:58:11 by sum               #+#    #+#             */
/*   Updated: 2022/10/10 17:59:42 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *format, va_list *ap, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (*format == 'p')
		ft_pointer(va_arg(*ap, void *), len);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (*format == 'u')
		ft_unsigned(va_arg(*ap, unsigned int), len);
	else if (*format == 'x' || *format == 'X')
		ft_hexa(va_arg(*ap, int), format, len);
	else if (*format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			ft_format(++str, &ap, &len);
		else
			ft_putchar(*str, &len);
		str++;
	}
	va_end (ap);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:49 by femorell          #+#    #+#             */
/*   Updated: 2022/10/26 16:44:21 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *ap, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_pointer(unsigned long int n);
int	ft_digit(int n);
int	ft_unsigned_int(unsigned int n);
int	ft_hexadecimal(unsigned int n, char c);

#endif

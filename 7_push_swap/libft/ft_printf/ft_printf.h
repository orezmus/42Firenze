/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:59:51 by sum               #+#    #+#             */
/*   Updated: 2022/10/10 18:01:46 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_hexa(unsigned long long nbr, const char *format, int *len);
void	ft_pointer(void *addr, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_unsigned(unsigned int nb, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putnbr_base(int nbr, const char *format, int *len);
void	ft_putchar(char c, int *len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:20:55 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 14:22:16 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	rt;

	rt = 0;
	if (c >= 0 && c <= 127)
		rt = 1;
	return (rt);
}

/*int main  (void)
{
	int a;
	int b;
	int c;
	int d;
	a = 0;
	c = 12;
	b = 127;
	d = 546;
	printf("%d : %d %d\n", a, ft_isascii(a), isascii(a));
	printf("%d : %d %d\n", b, ft_isascii(b), isascii(b));
	printf("%d : %d %d\n", c, ft_isascii(c), isascii(c));
	printf("%d : %d %d\n", d, ft_isascii(d), isascii(d));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:17:29 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:17:30 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	rt;

	rt = 0;
	if (c > 31 && c < 127)
		rt = 1;
	return (rt);
}

/*int main  (void)
{
	int a;
	int b;
	int c;
	int d;
	a = '	';
	c = '\0';
	b = ' ';
	d = '$';
	printf("%d : %d %d\n", a, ft_isprint(a), isprint(a));
	printf("%d : %d %d\n", b, ft_isprint(b), isprint(b));
	printf("%d : %d %d\n", c, ft_isprint(c), isprint(c));
	printf("%d : %d %d\n", d, ft_isprint(d), isprint(d));
}*/

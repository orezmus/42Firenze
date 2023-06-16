/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:14:28 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 14:15:20 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	rt;

	rt = 0;
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		rt = 1;
	return (rt);
}

/*int main  (void)
{
	int a;
	int b;
	int c;
	int d;
	int f;
	int g;
	a = 'a';
	c = 'Z';
	b = '4';
	d = '$';
	f = '0';
	g = ' ';
	printf("%d : %d %d\n", a, ft_isalnum(a), isalnum(a));
	printf("%d : %d %d\n", b, ft_isalnum(b), isalnum(b));
	printf("%d : %d %d\n", c, ft_isalnum(c), isalnum(c));
	printf("%d : %d %d\n", d, ft_isalnum(d), isalnum(d));
	printf("%d : %d %d\n", f, ft_isalnum(f), isalnum(f));
	printf("%d : %d %d\n", g, ft_isalnum(g), isalnum(g));
}*/

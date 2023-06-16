/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:06:26 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 14:07:52 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	rt;

	rt = 1;
	if (c < 48 || c > 57)
		rt = 0;
	return (rt);
}

/*int main  (void)
{
	int a;
	int b;
	int c;
	int d;
	a = 'A';
	c = '@';
	b = '4';
	d = '0';
	printf("%d : %d %d\n", a, ft_isdigit(a), isdigit(a));
	printf("%d : %d %d\n", b, ft_isdigit(b), isdigit(b));
	printf("%d : %d %d\n", c, ft_isdigit(c), isdigit(c));
	printf("%d : %d %d\n", d, ft_isdigit(d), isdigit(d));
}*/

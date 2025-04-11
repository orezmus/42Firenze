/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:16:58 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:16:59 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	rt;

	rt = 1;
	if (c < 65 || (c > 90 && c < 97) || c > 122)
		rt = 0;
	return (rt);
}

/*int main  (void)
{
	int a;
	int b;
	int c;
	int d;
	a = 'a';
	c = 'Z';
	b = '4';
	d = '$';
	printf("%d : %d %d\n", a, ft_isalpha(a), isalpha(a));
	printf("%d : %d %d\n", b, ft_isalpha(b), isalpha(b));
	printf("%d : %d %d\n", c, ft_isalpha(c), isalpha(c));
	printf("%d : %d %d\n", d, ft_isalpha(d), isalpha(d));
}*/

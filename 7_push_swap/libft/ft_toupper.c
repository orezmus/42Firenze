/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:47:07 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 16:47:20 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c -= 32;
	}
	return (c);
}

/*int	main()
{
	int a = 'z';
	int b = 'a';
	int c = 'A';
	int d = '#';
	printf("expected\n");
	printf("%c\n", toupper(a));
	printf("%c\n", toupper(b));
	printf("%c\n", toupper(c));
	printf("%c\n", toupper(d));
	printf("yours\n");
	printf("%c\n", ft_toupper(a));
	printf("%c\n", ft_toupper(b));
	printf("%c\n", ft_toupper(c));
	printf("%c\n", ft_toupper(d));
}*/

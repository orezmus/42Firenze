/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:53:04 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 16:53:13 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

/*int	main()
{
	int a = 'z';
	int b = 'a';
	int c = 'A';
	int d = '#';
	printf("expected\n");
	printf("%c\n", tolower(a));
	printf("%c\n", tolower(b));
	printf("%c\n", tolower(c));
	printf("%c\n", tolower(d));	
	printf("yours\n");
	printf("%c\n", ft_tolower(a));
	printf("%c\n", ft_tolower(b));
	printf("%c\n", ft_tolower(c));
	printf("%c\n", ft_tolower(d));
	}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:22:58 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:23:00 by femorell         ###   ########.fr       */
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

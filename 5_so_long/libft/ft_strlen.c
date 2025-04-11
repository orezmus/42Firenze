/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:21:19 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:21:20 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/*int	main(void)
{
	char *str, *str2;

	str = "Hello ";
	str2 = "Pineapple";
	printf("expected: %lu\n", strlen(str));
	printf("yours: %d\n\n", ft_strlen(str));
        printf("expected: %lu\n", strlen(str2));
        printf("yours: %d\n", ft_strlen(str2));
}*/

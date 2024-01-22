/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:59 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 14:31:09 by sum              ###   ########.fr       */
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

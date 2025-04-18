/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:16:39 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:16:40 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(char *)s = '\0';
		s++;
	}
	return ;
}

/*int	main(void)
{
	char arr[] = "Hello world";
	char aee[] = "Hello world";
	int n = 7*sizeof(char);
	printf("%ld\n", sizeof(arr));	
	bzero(arr,n);

	printf("expected: %s\n", arr);
	printf("%ld\n", sizeof(arr));
	
	ft_bzero(aee,n);
	printf("yours: %s\n", aee);
	printf("%ld\n", sizeof(aee));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:50 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:51 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((char *)s)[n] = (char)c;
	return (s);
}

/*int	main(void)
{
	char arr[] = "Hello world";
	char aee[] = "Hello world";
	int c = 'p';
	int n = 7*sizeof(char);
		
	memset(arr,c,n);
	ft_memset(aee,c,n);
	
	printf("expected: %s\n", arr);

	printf("yours: %s\n", aee);

}*/

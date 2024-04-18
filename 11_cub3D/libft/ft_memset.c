/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:32 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 14:40:35 by sum              ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:10 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 16:29:18 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	i = 0;
	if (lend >= size || size == 0)
	{
		return (lens + size);
	}
	else
	{
		while (lend + i < size - 1 && src [i] != '\0')
		{
			dest[lend + i] = src[i];
			i++;
		}
		dest[lend + i] = '\0';
		return (lend + lens);
	}
}

/*int				main(void)
{
	char			dest[15] = "Do you want ";
	char			src[20] = "add your letter?";
	size_t	size, size1, size2;
	
	size=0;
	size1 = 10;
	size2 = 20;
	printf("\ndest size: %d, dest len: %d, src len: %d\n\n" , 15, 12, 16);
	
	
	printf("size: %ld\n",size);
	printf("expected : %ld\n", strlcat(dest, src, size));
	printf("yours %ld\n\n", ft_strlcat(dest, src, size));
	
	printf("size: %ld\n",size1);
	printf("expected: %ld\n", strlcat(dest, src, size1));
	printf("yours: %ld\n\n", ft_strlcat(dest, src, size1));
	
	printf("size: %ld\n",size2);
	printf("expected: %ld\n", strlcat(dest, src, size2));
	printf("yours: %ld\n", ft_strlcat(dest, src, size2));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:35 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:36 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*r1;
	char	*r2;
	size_t	i;

	i = 0;
	r1 = (char *)s1;
	r2 = (char *)s2;
	while (i < n)
	{
		if (r1[i] != r2[i])
			return ((unsigned char)r1[i] - (unsigned char)r2[i]);
		i++;
	}
	return (0);
}

/*int		main(void)
{

	
	printf("%d\n", memcmp("t\200", "t\0", 2));
	printf("%d\n", ft_memcmp("t\200", "t\0", 2));
	
	printf("%d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	char	*str1, *str2, *str3, *str4, *str5, *str6;

	str1 = "Hello A world";
	str2 = "Hello Z world";
	printf("Hello A world / Hello Z world\n");
	printf("expected: %d\n", memcmp(str1, str2,7));
	printf("yours: %d\n\n", ft_memcmp(str1, str2,7));
	str3 = "Hello a world";
        str4 = "Hello Z world";
        printf("Hello a world / Hello Z world\n");
        printf("expected: %d\n", memcmp(str3, str4,7));
        printf("yours: %d\n\n", ft_memcmp(str3, str4,7));
	str5 = "Hello world";
        str6 = "Hello world";
        printf("Hello world / Hello world\n");
        printf("expected: %d\n", memcmp(str5, str6,13));
        printf("yours: %d\n", ft_memcmp(str5, str6,13));

}*/

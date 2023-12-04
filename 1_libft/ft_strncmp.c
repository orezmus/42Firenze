/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:35:42 by saclemen          #+#    #+#             */
/*   Updated: 2022/05/19 00:32:47 by saclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	i = 0;
	while ((r1[i] || r2[i]) && (i < n))
	{
		if (r1[i] < r2[i])
		{
			return (-1);
		}
		else if (r1[i] > r2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/*int		main(void)
{

	printf("expected: %d\n",strncmp("test\200", "test\0", 6));
	printf("yourse: %d\n\n", ft_strncmp("test\200", "test\0", 6));
	char	*str1, *str2, *str3;
	int	a,b;

	str1 = "christmas";
	
	str2 = "chriszmswoth";
	str3 = "cheershlel";
	a=3;
	b=6;
	printf("expected: %d\n", strncmp(str1, str2,a));
	printf("yourse: %d\n\n", ft_strncmp(str1, str2,a));
	
	printf("expected: %d\n", strncmp(str1, str2,b));
        printf("yours: %d\n\n", ft_strncmp(str1, str2,b));
        
        printf("expected: %d\n", strncmp(str1, str3,b));
        printf("yours: %d\n", ft_strncmp(str1, str3,b));
}*/

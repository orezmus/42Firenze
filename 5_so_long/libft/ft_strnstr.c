/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:21:39 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:21:40 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[j + i] == little[j] && j + i < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int		main(void)
{
	char	*str;
	char	*to_find;

	str = "Find this letter";
	to_find = "in";
	printf("expected: %s\n", strnstr(str, to_find,6));
	printf("%s\n\n", ft_strnstr(str, to_find,6));
	to_find = "";
	printf("expected: %s\n", strnstr(str, to_find,2));
	printf("%s\n\n", ft_strnstr(str, to_find,2));
	to_find = "ette";
	printf("expected: %s\n", strnstr(str, to_find,3));
	printf("%s\n\n", ft_strnstr(str, to_find,3));
	to_find = "t";
	printf("expected: %s\n", strnstr(str, to_find,0));
	printf("%s\n\n", ft_strnstr(str, to_find,0));
	to_find = "r";
	printf("expected: %s\n", strnstr(str, to_find,1));
	printf("%s\n", ft_strnstr(str, to_find,1));
}*/

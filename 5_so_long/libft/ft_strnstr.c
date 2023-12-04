/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:55:01 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 19:06:11 by sum              ###   ########.fr       */
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

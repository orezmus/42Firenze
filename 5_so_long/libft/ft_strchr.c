/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:36 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:20:38 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*rt;

	rt = NULL;
	while (*s != '\0' && *s != (char)c)
		++s;
	if (*s == (char)c)
		rt = (char *)s;
	return (rt);
}

/*int	main()
{
	const char *s = "123456789";
	int c1 = '1';
	int c2 = '4';
	int c3 = '\0';
	int c4 = 'e';

	printf("expected:\n");
	printf("%s\n",strchr(s,c1));
	printf("%s\n",strchr(s,c2));
	printf("%s\n",strchr(s,c3));
	printf("yours:\n");
	printf("%s\n",ft_strchr(s,c1));
	printf("%s\n",ft_strchr(s,c2));
	printf("%s\n",ft_strchr(s,c3));
	printf("%s\n",ft_strchr(s,c4));
}*/

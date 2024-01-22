/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:30 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 17:34:51 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*rt;
	const char	*temp;

	rt = NULL;
	temp = s;
	while (*temp != '\0')
		++temp;
	while (*temp != (char)c && temp != s)
		--temp;
	if (*temp == (char)c)
		rt = (char *)temp;
	return (rt);
}

/*int	main()
{
	const char *s = "1283852123";
	int c1 = '1';
	int c2 = '8';
	int c3 = '\0';
	int c4 = 'e';

	printf("expected:\n");
	printf("%s\n",strrchr(s,c1));
	printf("%s\n",strrchr(s,c2));
	printf("%s\n",strrchr(s,c3));
	printf("yours:\n");
	printf("%s\n",ft_strrchr(s,c1));
	printf("%s\n",ft_strrchr(s,c2));
	printf("%s\n",ft_strrchr(s,c3));
	printf("%s\n",ft_strrchr(s,c4));
}*/

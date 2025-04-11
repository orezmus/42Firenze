/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:21:25 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:21:27 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	i = 0;
	if (!s || !f)
		return (0);
	map = (char *)malloc(sizeof(char) * len);
	if (!map)
		return (0);
	while (s[i] != '\0')
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}

/*char	sample(unsigned int a, char c)
{
	char	i;
	
	i = a % 10 + c;
	
	return (i); 
}
	
int	main()
{
	char s[] = "hello";
	char *map = ft_strmapi(s, &sample);
	printf("%s", map);
}*/

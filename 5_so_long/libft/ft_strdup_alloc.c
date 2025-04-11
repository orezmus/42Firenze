/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:51 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:20:52 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_alloc(const char *s, t_alloc *alloc)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_malloc(sizeof(char) * (ft_strlen(s) + 1), &alloc);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
/*int		main(void)
{
	char	*str;
	char	*allocated;

	str = "Hello World with malloc()";
	printf("x  : base  : $%s$ \n", str, );
	allocated = strdup(str);
	printf("c  : alloc : $%s$ \n", allocated, );
	allocated = ft_strdup(str);
	printf("ft : alloc : $%s$ \n", allocated, );
}	*/

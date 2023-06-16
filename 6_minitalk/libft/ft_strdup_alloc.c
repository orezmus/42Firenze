/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:38:12 by sum               #+#    #+#             */
/*   Updated: 2022/05/21 19:38:14 by sum              ###   ########.fr       */
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

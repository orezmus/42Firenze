/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:39 by sum               #+#    #+#             */
/*   Updated: 2023/03/13 15:13:40 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_alloc(char const *s1, char const *s2, t_alloc **alloc)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), alloc);
	if (!str)
		return (NULL);
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	return (str);
}

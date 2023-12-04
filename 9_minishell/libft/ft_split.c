/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:05 by sum               #+#    #+#             */
/*   Updated: 2022/10/05 15:35:08 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

size_t	ft_wordcnt(const char *s, char d)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != d)
		{
			cnt++;
			while (s[i] && s[i] != d)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char	*ft_worddup(const char *s, char d)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split(const char *s, char d)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(ft_wordcnt(s, d) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_wordcnt(s, d) && s[j])
	{
		if (s[j] != d)
		{
			ptr[i++] = ft_worddup(&(s[j]), d);
			if (!ptr)
				return (ft_freeall(ptr));
			while (s[j] && s[j] != d)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}

/*int main(void)
{
	char str[500] = ".";

	char c = 'i';
	char **result = ft_split(str, c);
	printf("%d\n",count_word(str,c));
	printf("%s\n%c\n--------------\n", str, c);
	for(int i = 0; result[i]; i++)
		printf("%s\n", result[i]);

	return 0;
}*/

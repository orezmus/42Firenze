/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:26:07 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 16:26:13 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (i < size - 1 && src [i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}
/*int main(void){
        char dest[] = "Hello World";
	char scr[] = "kiwi";
	char scr1[] = "pineapple";
	unsigned int a = 4;
	unsigned int b=7;
        printf("expect: %d\n",ft_strlcpy (dest, scr,a));
        printf("yours: %ld\n",strlcpy (dest, scr,a));
	printf("copied result: %s\n\n", dest);
	printf("expect: %ld\n",strlcpy (dest, scr1,b));
	printf("yours: %d\n",ft_strlcpy (dest, scr1,b));
	printf("copied result: %s\n", dest);
}*/

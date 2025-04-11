/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:44 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:46 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*rt;

	rt = dest;
	if (dest <= src)
	{
		while (n--)
		{
			*(char *)dest = *(char *)src;
			dest++;
			src++;
		}
	}
	else
	{
		dest = (char *)dest + n - 1 ;
		src = (char *)src + n - 1;
		while (n--)
		{
			*(char *)dest = *(char *)src;
			dest--;
			src--;
		}
	}
	return (rt);
}

/*int main ()
{
	char s[100] = "1234567890";
	char a[100] = "1234567890";
	ft_memmove(s+4,s+2,5);
	memmove(a+4,a+2,5);
	printf("expected: %s\n",a);
	printf("yours: %s", s);
}*/

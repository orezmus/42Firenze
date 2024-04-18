/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:43:19 by sum               #+#    #+#             */
/*   Updated: 2022/10/03 15:51:22 by sum              ###   ########.fr       */
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

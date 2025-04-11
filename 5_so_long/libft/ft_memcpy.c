/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:40 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:41 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*rt;

	rt = dest;
	while (n--)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
	}
	return (rt);
}

/*int	main(void)
{
	char agg[100] = "bea";
	char arr[100] = "bea";
	char aee[] = "bello";

	int n = 6;
	//int m = 11;
	memcpy(agg,aee,n);
	ft_memcpy(arr,aee,n);
	//memcpy(agg,aee,m);
	//ft_memcpy(arr,aee,m);
	
	printf("expected: %s\n",agg);
	printf("yours: %s\n",arr);
}*/

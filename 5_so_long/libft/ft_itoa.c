/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:17:35 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:17:36 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	t;
	long	a;

	t = n;
	a = num_len(n);
	str = ft_calloc((a + 1), sizeof(char));
	if (str == 0)
		return (0);
	if (t < 0)
		t = -t;
	while (a--)
	{
		str[a] = (t % 10) + 48;
		t /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int main ()
{
	int n = -2147483648LL;
	int m = 0;
	printf("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(m));
}*/

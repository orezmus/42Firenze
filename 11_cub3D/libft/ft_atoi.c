/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:26:20 by sum               #+#    #+#             */
/*   Updated: 2022/05/19 18:26:22 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	return (sign * value);
}

/*int		main(void)
{
	char *str, *str2;

	str = "";
	printf("%d: %d\n", atoi(str),ft_atoi(str));
	//str2= "-1556622222255";
	//printf("%d: %d\n", atoi(str2),ft_atoi(str2));

}*/

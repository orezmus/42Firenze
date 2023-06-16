/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:18:08 by sum               #+#    #+#             */
/*   Updated: 2023/05/30 21:45:35 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_isdigit(int c)
{
	int	rt;

	rt = 1;
	if (c < 48 || c > 57)
		rt = 0;
	return (rt);
}

long long	ft_atoi_long(char *str)
{	
	int			sign;
	long long	value;

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

int	check_valid(char *str)
{	
	int	i;

	i = 0;
	if (ft_strlen(str) > 11 || \
		ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
	{	
		error_free();
		return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{	
			error_free();
			return (0);
		}		
	}
	return (1);
}

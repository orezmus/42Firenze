/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:27 by sum               #+#    #+#             */
/*   Updated: 2023/04/24 15:43:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_valid(char *str, t_var *var)
{	
	int	i;

	i = 0;
	if (ft_strlen(str) > 11 || \
		ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
	{	
		error_free(var);
		return (0);
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{	
			error_free(var);
			return (0);
		}		
	}
	return (1);
}

int	check_size(char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
			count += ft_wordcnt(av[i], ' ');
		else
			count++;
		i++;
	}
	return (count);
}

void	check_dupe(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->size)
	{
		j = i + 1;
		while (j < var->size)
		{
			if (var->arr[i] == var->arr[j])
				error_free(var);
			j++;
		}
		i++;
	}
}

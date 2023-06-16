/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:27 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 19:10:33 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_valid(char *str, t_var *var)
{	
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{	
			error_free(var, NULL);
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
				error_free(var, NULL);
			j++;
		}
		i++;
	}
}

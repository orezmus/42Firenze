/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:21:36 by sum               #+#    #+#             */
/*   Updated: 2023/04/28 14:12:38 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_stack(t_var *var)
{
	t_node	*node;

	while (var->a->size > 0)
	{
		node = pop(var->a);
		free(node);
	}
	free(var->a);
	free(var->b);
	free(var->arr);
}

void	error_free(t_var *var, char *line)
{
	free_stack(var);
	free(line);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	arr_to_stack(t_var *var)
{
	int	i;

	i = var->size;
	while (i > 0)
	{
		push(var->a, var->arr[i - 1]);
		i--;
	}
}

static void	parsing(char **av, t_var *var)
{
	int		i;
	int		j;
	int		h;
	char	**temp;

	i = 1;
	h = 0;
	while (av[i] != NULL)
	{
		if (ft_strchr(av[i], ' '))
		{
			temp = ft_split(av[i], ' ');
			j = 0;
			while (temp[j])
			{
				if (check_valid(temp[j], var))
					var->arr[h++] = ft_atoi(temp[j]);
				free(temp[j]);
				j++;
			}
		}
		else if (check_valid(av[i], var))
			var->arr[h++] = ft_atoi(av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_var	var;
	char	*line;

	if (ac < 2)
		return (0);
	init_stack(&var);
	var.size = check_size(av);
	var.arr = (int *)malloc(sizeof(int) * var.size);
	parsing(av, &var);
	check_dupe(&var);
	arr_to_stack(&var);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		cmd_input(&var, line);
		free(line);
	}
	if (is_sorted(var.a, var.a->size) && var.b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&var);
}

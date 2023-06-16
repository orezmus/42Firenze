/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:18 by sum               #+#    #+#             */
/*   Updated: 2023/04/28 18:17:27 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = stack->size;
	node = stack->top;
	ft_printf("------- top --------\n");
	while (--i >= 0)
	{
		ft_printf("%d\n", node->data);
		node = node->next;
	}
	ft_printf("------- bottom --------\n");
}

void	arr_sorted(int *arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 5)
	{
		j = i + 1;
		while (j < 5)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	pivot_mid(t_var *var, int size)
{
	t_node	*node;
	int		*arr;
	int		pivot;
	int		i;

	i = 0;
	node = var->a->top;
	arr = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
	arr_sorted(arr);
	pivot = arr[2];
	free(arr);
	return (pivot);
}

int	pivot(t_stack *stack, int count, char c)
{
	t_node	*temp;
	int		min;
	int		max;
	int		l;
	int		s;

	temp = stack->top;
	min = temp->data;
	max = temp->data;
	while (count-- > 1)
	{
		if (min > temp->next->data)
			min = temp->next->data;
		else if (max < temp->next->data)
			max = temp->next->data;
		temp = temp->next;
	}
	l = (min + max) / 2;
	s = (l + min) / 2;
	if (c == 'l')
		return (l);
	else
		return (s);
}

void	rotate_back(t_var *var, t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->ra > cmd->rb)
	{
		while (++i < cmd->rb)
			rrr(var->a, var->b);
		while (++i <= cmd->ra && cmd->rb == var->b->size)
			rra(var->a);
		while (i++ <= cmd->ra && cmd->size < var->a->size)
			rra(var->a);
	}
	else
	{
		while (++i < cmd->ra)
			rrr(var->a, var->b);
		while (++i <= cmd->rb && cmd->ra == var->a->size)
			rrb(var->b);
		while (i++ <= cmd->rb && cmd->size < var->b->size)
			rrb(var->b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:11 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 17:47:40 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack, int size)
{
	t_node	*temp;

	temp = stack->top;
	if (size == 0 || size == 1)
		return (1);
	while (size-- > 1)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack, int size)
{
	t_node	*temp;

	temp = stack->top;
	if (size == 0 || size == 1)
		return (1);
	while (size-- > 1)
	{
		if (temp->data > temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	sorted_b(t_var *var, int size)
{
	if (size == 0)
		return (1);
	if (size == 1)
	{
		pa(var->a, var->b);
		return (1);
	}
	else if (size == 2)
	{
		if (var->b->top->data < var->b->top->next->data)
			sb(var->b);
		pa(var->a, var->b);
		pa(var->a, var->b);
		return (1);
	}
	else if (is_rev_sorted(var->b, size))
	{
		while (size-- > 0)
			pa(var->a, var->b);
		return (1);
	}
	return (0);
}

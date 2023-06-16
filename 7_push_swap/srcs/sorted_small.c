/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:32 by sum               #+#    #+#             */
/*   Updated: 2023/04/24 15:39:48 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sorted_plus(t_stack *stack)
{
	if (stack->top->data < stack->top->next->data)
	{
		if (stack->top->next->data < stack->top->next->next->data)
			return ;
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (stack->top->data > stack->top->next->next->data)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
}

void	three_sorted(t_stack *stack)
{
	if (stack->size == 3)
	{
		if (stack->top->data > stack->top->next->data
			&& stack->top->data > stack->top->next->next->data)
			ra(stack);
		else if (stack->top->next->data > stack->top->data
			&& stack->top->next->data > stack->top->next->next->data)
			rra(stack);
	}
	else
		three_sorted_plus(stack);
	if (!is_sorted(stack, 2))
		sa(stack);
}

void	five_sorted(t_var *var, int size)
{
	int		i;

	i = 0;
	while (size != 3)
	{
		if (var->a->top->data < pivot_mid(var, size))
		{
			pb(var->a, var->b);
			size--;
		}	
		else
		{
			ra(var->a);
			i++;
		}
	}
	while (var->a->size != size && i-- > 0)
		rra(var->a);
	small_sorted(var, 3);
	while (size++ != 5)
	{
		pa(var->a, var->b);
		small_sorted(var, 3);
	}	
}

int	small_sorted(t_var *var, int size)
{
	if (size == 2 && !is_sorted(var->a, 2))
	{
		sa(var->a);
		return (1);
	}	
	else if (size == 3 && !is_sorted(var->a, 3))
	{
		three_sorted(var->a);
		return (1);
	}
	else if (size == 5 && !is_sorted(var->a, 5))
	{
		five_sorted(var, size);
		return (1);
	}
	return (0);
}

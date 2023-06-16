/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:24:13 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 17:47:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

void	push_back(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = init_node(data);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->top == NULL)
		return (0);
	else
	{
		node = stack->top;
		if (stack->top->next)
		{	
			stack->top = stack->top->next;
			stack->top->prev = NULL;
		}
		else
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
	}
	stack->size--;
	return (node);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*node;

	if (stack->top == NULL)
		return (0);
	else
	{
		node = stack->bottom;
		if (stack->bottom->prev)
		{
			stack->bottom = stack->bottom->prev;
			stack->bottom->next = NULL;
		}
		else
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
	}
	stack->size--;
	return (node);
}

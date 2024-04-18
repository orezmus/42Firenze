/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmd3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:03 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 18:02:10 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size == 0)
		return ;
	temp = pop_back(stack_a);
	push(stack_a, temp->data);
	free(temp);
}

void	rrb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->size == 0)
		return ;
	temp = pop_back(stack_b);
	push(stack_b, temp->data);
	free(temp);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->size != 0)
	{	
		temp = pop_back(stack_a);
		push(stack_a, temp->data);
		free(temp);
	}
	if (stack_b->size != 0)
	{	
		temp = pop_back(stack_b);
		push(stack_b, temp->data);
		free(temp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:57 by sum               #+#    #+#             */
/*   Updated: 2023/04/28 14:14:28 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size == 0)
		return ;
	temp = pop(stack_a);
	push_back(stack_a, temp->data);
	free(temp);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->size == 0)
		return ;
	temp = pop(stack_b);
	push_back(stack_b, temp->data);
	free(temp);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->size != 0)
	{	
		temp = pop(stack_a);
		push_back(stack_a, temp->data);
		free(temp);
	}
	if (stack_b->size != 0)
	{	
		temp = pop(stack_b);
		push_back(stack_b, temp->data);
		free(temp);
	}
	ft_putstr_fd("rr\n", 1);
}

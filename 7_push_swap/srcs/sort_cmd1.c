/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmd1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:43 by sum               #+#    #+#             */
/*   Updated: 2023/04/13 16:28:47 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size <= 1)
		return ;
	temp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size <= 1)
		return ;
	temp = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sa(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b->size == 0)
		return ;
	node = pop(stack_b);
	push(stack_a, node->data);
	free(node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->size == 0)
		return ;
	node = pop(stack_a);
	push(stack_b, node->data);
	free(node);
	ft_putstr_fd("pb\n", 1);
}

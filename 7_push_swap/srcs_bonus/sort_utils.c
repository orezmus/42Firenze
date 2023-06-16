/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:18 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 19:31:56 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	cmd_input(t_var *var, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(var->a);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(var->b);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(var->a, var->b);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(var->a, var->b);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(var->a, var->b);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(var->a);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(var->b);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(var->a, var->b);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(var->a);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(var->b);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(var->a, var->b);
	else
		error_free(var, line);
}

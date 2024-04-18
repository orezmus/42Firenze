/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:31:17 by sum               #+#    #+#             */
/*   Updated: 2023/04/28 14:15:56 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_var *var)
{
	var->a = (t_stack *)malloc(sizeof(t_stack));
	var->b = (t_stack *)malloc(sizeof(t_stack));
	if (!var->a || !var->b)
		error_free(var);
	var->a->size = 0;
	var->a->top = NULL;
	var->a->bottom = NULL;
	var->b->size = 0;
	var->b->top = NULL;
	var->b->bottom = NULL;
}

t_node	*init_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_putstr_fd("Error\n", 2);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_cmd	*init_size(int size)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		ft_putstr_fd("Error\n", 2);
	cmd->pa = 0;
	cmd->pb = 0;
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->size = size;
	cmd->pivot_l = 0;
	cmd->pivot_s = 0;
	return (cmd);
}

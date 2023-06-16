/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:34 by sum               #+#    #+#             */
/*   Updated: 2023/04/28 18:18:58 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a(t_var *var, t_cmd *cmd, int size)
{
	int	i;

	i = 0;
	cmd->pivot_l = pivot(var->a, size, 'l');
	cmd->pivot_s = pivot(var->a, size, 's');
	while (i++ < size)
	{
		if (var->a->top->data > cmd->pivot_l)
		{
			ra(var->a);
			cmd->ra++;
		}
		else
		{
			pb(var->a, var->b);
			cmd->pb++;
			if (var->b->top->data > cmd->pivot_s)
			{
				rb(var->b);
				cmd->rb++;
			}
		}
	}
}

void	sort_b(t_var *var, t_cmd *cmd, int size)
{
	int	i;

	i = 0;
	cmd->pivot_l = pivot(var->b, size, 'l');
	cmd->pivot_s = pivot(var->b, size, 's');
	while (i++ < size)
	{
		if (var->b->top->data <= cmd->pivot_s)
		{
			rb(var->b);
			cmd->rb++;
		}
		else
		{
			pa(var->a, var->b);
			cmd->pa++;
			if (var->a->top->data <= cmd->pivot_l)
			{
				ra(var->a);
				cmd->ra++;
			}
		}
	}
}

void	b_to_a(t_var *var, int size)
{
	t_cmd	*cmd;

	if (sorted_b(var, size))
		return ;
	cmd = init_size(size);
	sort_b(var, cmd, size);
	a_to_b(var, cmd->pa - cmd->ra);
	rotate_back(var, cmd);
	a_to_b(var, cmd->ra);
	b_to_a(var, cmd->rb);
	free(cmd);
}

void	a_to_b(t_var *var, int size)
{
	t_cmd	*cmd;

	if (is_sorted(var->a, size))
		return ;
	if (small_sorted(var, size))
		return ;
	cmd = init_size(size);
	sort_a(var, cmd, size);
	rotate_back(var, cmd);
	a_to_b(var, cmd->ra);
	b_to_a(var, cmd->rb);
	b_to_a(var, cmd->pb - cmd->rb);
	free(cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:20:52 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 21:42:01 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_redir(t_list *command)
{
	t_cmd	*cmd;
	t_cmd	*cmd_next;

	cmd = (t_cmd *)command->content;
	if (!command->next)
	{
		print_msg(1, " `newline'\n");
		exit_status(NULL, 258);
		return (258);
	}
	cmd_next = (t_cmd *)command->next->content;
	if ((cmd->type <= PIPE && cmd_next->type <= PIPE))
	{
		print_msg(1, cmd_next->line);
		exit_status(NULL, 258);
		return (258);
	}
	else if (cmd->type != REDIRIN && opendir(cmd_next->line))
	{
		print_msg(2, cmd_next->line);
		exit_status(NULL, 1);
		return (1);
	}
	return (0);
}

int	check_syntax(t_data **data)
{
	t_cmd	*cmd;
	t_list	*current;

	current = (*data)->command;
	if (!current)
		return (1);
	cmd = (t_cmd *)current->content;
	if (cmd->type == PIPE)
	{
		print_msg(1, " `|'\n");
		free_list(*data);
		exit_status(NULL, 258);
		return (258);
	}
	while (current)
	{
		cmd = (t_cmd *)current->content;
		if (cmd->type <= PIPE && check_redir(current))
		{
			free_list(*data);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:20:52 by sum               #+#    #+#             */
/*   Updated: 2024/01/09 11:55:06 by femorell         ###   ########.fr       */
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
		print_msg(1, NULL, " `newline'\n");
		g_exit_status = 258;
		return (1);
	}
	cmd_next = (t_cmd *)command->next->content;
	if ((cmd->type >= REDIROUT && cmd->type <= HEREDOC)
		&& (cmd_next->type >= REDIROUT && cmd_next->type <= HEREDOC))
	{
		print_msg(1, NULL, cmd_next->line);
		g_exit_status = 258;
		return (1);
	}
	else if (cmd->type != REDIRIN && opendir(cmd_next->line))
	{
		print_msg(2, NULL, cmd_next->line);
		g_exit_status = 1;
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
		return (0);
	cmd = (t_cmd *)current->content;
	if (cmd->type == PIPE)
	{
		print_msg(1, NULL, " `|'\n");
		free_list(*data);
		g_exit_status = 258;
		return (0);
	}
	while (current)
	{
		cmd = (t_cmd *)current->content;
		if (cmd->type > ARG && check_redir(current))
		{
			free_list(*data);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

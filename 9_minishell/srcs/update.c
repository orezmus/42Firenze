/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:35 by femorell          #+#    #+#             */
/*   Updated: 2024/02/03 09:28:15 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_builtin(char *str)
{
	if (!ft_strcmp(str, "pwd") || !ft_strcmp(str, "echo")
		|| !ft_strcmp(str, "cd") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "export") || !ft_strcmp(str, "unset")
		|| !ft_strcmp(str, "exit"))
		return (1);
	else
		return (0);
}

static void	update_redir(t_data **data)
{
	t_cmd	*cmd;
	t_cmd	*cmd_next;
	t_list	*current;

	current = (*data)->command;
	while (current)
	{
		if (current->next)
		{
			cmd = (t_cmd *)current->content;
			cmd_next = (t_cmd *)current->next->content;
			if (cmd->type >= REDIROUT && cmd->type <= APPEND)
			{
				if (cmd->type == REDIRIN && opendir(cmd_next->line))
					cmd_next->type = DIR;
				else
					cmd_next->type = FILE;
			}
			if (cmd->type == HEREDOC)
				cmd_next->type = FILE;
		}
		current = current->next;
	}
}

void	update_command(t_data **data)
{
	t_cmd	*cmd;
	t_cmd	*cmd_next;
	t_list	*current;

	current = (*data)->command;
	while (current)
	{
		if (current->next)
		{
			cmd = (t_cmd *)current->content;
			cmd_next = (t_cmd *)current->next->content;
			if ((cmd->type <= PIPE || cmd->type > ARG) && cmd_next->type == ARG)
			{
				if (check_builtin(cmd_next->line))
					cmd_next->type = BUILTIN;
				else
					cmd_next->type = CMD;
			}
		}
		current = current->next;
	}
}

int	update_arg(t_data **data)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)(*data)->command->content;
	if (!(*cmd->line))
	{
		ft_putstr_fd("\n", 2);
		free_list(*data);
		return (1);
	}
	if (cmd->type == ARG || cmd->type == DQUOTE || cmd->type == SQUOTE)
	{
		if (check_builtin(cmd->line))
			cmd->type = BUILTIN;
		else
			cmd->type = CMD;
	}
	update_redir(data);
	update_command(data);
	return (0);
}

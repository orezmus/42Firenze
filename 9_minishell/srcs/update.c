/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:35 by femorell          #+#    #+#             */
/*   Updated: 2024/01/09 12:03:17 by femorell         ###   ########.fr       */
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

static void	update_redir(t_cmd *cmd, t_cmd *cmd_next)
{
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

static void	update_meta(t_data **data)
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
			update_redir(cmd, cmd_next);
			if (cmd->type == PIPE && cmd_next->type == ARG)
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
		ft_putstr_fd("Command '' not found\n", 2);
		free_list(*data);
		return (0);
	}
	if (cmd->type == ARG)
	{
		if (check_builtin(cmd->line))
			cmd->type = BUILTIN;
		else
			cmd->type = CMD;
	}
	update_meta(data);
	expansion(data);
	return (1);
}

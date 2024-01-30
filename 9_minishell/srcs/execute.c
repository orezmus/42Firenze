/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:23:54 by sum               #+#    #+#             */
/*   Updated: 2024/01/30 11:37:35 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_list(t_data *data, t_list *command)
{
	if (((t_cmd *)command->content)->type == CMD)
		exec_cmd(data, command);
	close_fd();
	exec_fork_builtin(data, command);
	exit(0);
}

void	exec_dup(t_data *data)
{
	if (data->flag < data->arg)
	{
		dup2(data->fd[1][1], STDOUT_FILENO);
		close(data->fd[1][0]);
		close(data->fd[1][1]);
	}
	if (data->flag != 1)
	{
		dup2(data->fd[0][0], STDIN_FILENO);
		close(data->fd[0][0]);
		close(data->fd[0][1]);
	}
	if (data->fd[2][0] != 0)
	{
		dup2(data->fd[2][0], STDIN_FILENO);
		close(data->fd[2][0]);
	}
	if (data->fd[2][1] != 0)
	{
		dup2(data->fd[2][1], STDOUT_FILENO);
		close(data->fd[2][1]);
	}
}

void	exec_fork(t_data *data, t_list *command)
{
	pid_t	pid;

	data->fork = 1;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (data->fd[2][0] == -1 && data->arg == 1)
		{
			close_fd();
			exit(1);
		}
		exec_dup(data);
		exec_list(data, command);
	}
	else
	{
		if (data->flag != 1)
		{
			close(data->fd[0][0]);
			close(data->fd[0][1]);
		}
	}
	exec_builtin(data, command);
}

void	exec_redir(t_data *data, t_list *command)
{
	t_cmd	*cmd;

	data->fd[2][0] = 0;
	data->fd[2][1] = 0;
	while (command->next && ((t_cmd *)command->next->content)->type != PIPE \
			&& data->fd[2][0] != -1 && data->fd[2][1] != -1)
	{
		cmd = (t_cmd *)command->content;
		if (cmd->type == REDIRIN)
			redir_in(data, command->next);
		else if (cmd->type == REDIROUT)
			redir_out(data, command->next, 0);
		else if (cmd->type == APPEND)
			redir_out(data, command->next, 1);
		else if (cmd->type == HEREDOC)
			here_doc(data, command->next);
		command = command->next;
	}
}

void	execute(t_data *data)
{
	t_list	*current;
	int		status;
	int		std[2];

	init_execute(&data);
	current = data->command;
	while (current)
	{
		std[0] = dup(STDIN_FILENO);
		std[1] = dup(STDOUT_FILENO);
		if (data->arg > 1)
			pipe(data->fd[1]);
		exec_redir(data, current);
		if (data->fd[2][0] != -1)
			exec_fork(data, current);
		fd_backup(data, &std[0], &std[1]);
		while (current->next && ((t_cmd *)current->content)->type != PIPE)
			current = current->next;
		current = current->next;
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			exit_status(NULL, WEXITSTATUS(status));
	}
}

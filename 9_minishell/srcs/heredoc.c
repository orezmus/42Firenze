/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:30:15 by sum               #+#    #+#             */
/*   Updated: 2024/01/30 17:49:09 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit = 0;

void	child_heredoc(t_data *data, t_list *command)
{
	char	*temp;
	char	*line;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	line = ft_itoa(data->heredoc[0]);
	temp = ft_strjoin(".heredoc_", line);
	free(line);
	data->fd[2][0] = open(temp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(temp);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, ((t_cmd *)command->content)->line))
		{
			close(data->fd[2][0]);
			free(line);
			exit(0);
		}
		heredoc_nl(&line);
		expansion_heredoc(&data, &line);
		ft_putendl_fd(line, data->fd[2][0]);
		free(line);
	}
}

void	parent_heredoc(t_data *data)
{
	if (g_exit == 130)
	{
		unlink_heredoc(data);
		data->fd[2][0] = -1;
	}
}

void	write_heredoc(t_data *data, t_list *command)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_heredoc(data, command);
	else
	{
		waitpid(pid, NULL, 0);
		data->heredoc[0]++;
		parent_heredoc(data);
	}
}

int	exec_heredoc(t_data *data, t_list *command)
{
	t_cmd	*cmd;

	g_exit = 0;
	data->heredoc[0] = 0;
	data->heredoc[1] = 0;
	data->fd[2][0] = 0;
	while (command->next)
	{
		cmd = (t_cmd *)command->content;
		if (cmd->type == HEREDOC)
			write_heredoc(data, command->next);
		if (data->fd[2][0] == -1)
			return (1);
		command = command->next;
	}
	return (0);
}

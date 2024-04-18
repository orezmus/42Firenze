/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:28:04 by sum               #+#    #+#             */
/*   Updated: 2024/01/30 17:52:07 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	here_doc(t_data *data, t_list *command)
{
	char	*temp;
	char	*itoa;
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	itoa = ft_itoa(data->heredoc[1]++);
	temp = ft_strjoin(".heredoc_", itoa);
	free(itoa);
	data->fd[2][0] = open(temp, O_RDONLY);
	free(temp);
	if (data->fd[2][0] == -1)
	{
		print_error(cmd->line, NULL, strerror(errno));
		exit_status(NULL, 1);
	}
}

void	redir_in(t_data *data, t_list *command)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	data->fd[2][0] = open(cmd->line, O_RDONLY);
	if (data->fd[2][0] == -1)
	{
		print_error(cmd->line, NULL, strerror(errno));
		exit_status(NULL, 1);
	}
}

void	redir_out(t_data *data, t_list *command, int append)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	if (append == 0)
		data->fd[2][1] = open(cmd->line, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		data->fd[2][1] = open(cmd->line, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (data->fd[2][1] == -1)
	{
		print_error(cmd->line, NULL, strerror(errno));
		exit_status(NULL, 1);
	}
}

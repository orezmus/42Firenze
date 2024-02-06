/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:15:41 by femorell          #+#    #+#             */
/*   Updated: 2024/02/03 14:19:20 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_cmd(t_list *command)
{
	int		i;
	char	**cmdline;

	cmdline = (char **)malloc(sizeof(char *) * 256);
	i = 0;
	while (command && ((t_cmd *)command->content)->type != PIPE)
	{
		if (command && ((t_cmd *)command->content)->type < PIPE)
			command = command->next->next;
		if (command && ((t_cmd *)command->content)->type > PIPE)
		{
			cmdline[i++] = ((t_cmd *)command->content)->line;
			command = command->next;
		}
	}
	cmdline[i] = '\0';
	return (cmdline);
}

char	*path_info(char **temp, char *cmd)
{
	int		i;
	char	*path;

	i = -1;
	while (temp[++i])
	{
		path = ft_strjoin(temp[i], cmd);
		if (open(path, O_RDONLY) == -1)
			free(path);
		else
		{
			i = -1;
			free_split(temp);
			free(cmd);
			return (path);
		}
	}
	free_split(temp);
	free(cmd);
	return (NULL);
}

char	*get_path(t_data *data, char **cmdline)
{
	char	*temp;
	char	**temp_path;
	char	*path;

	if (ft_strchr(cmdline[0], '/'))
		return (ft_strdup(cmdline[0]));
	temp = extract_envp(&data, "PATH");
	temp_path = ft_split(temp, ':');
	free(temp);
	if (temp_path == NULL)
	{
		close_fd();
		print_error(cmdline[0], NULL, "No such file or directory");
		free_shell(data);
		free(cmdline);
		exit(127);
	}
	temp = ft_strjoin("/", cmdline[0]);
	path = path_info(temp_path, temp);
	return (path);
}

void	exec_cmd(t_data *data, t_list *command)
{
	int		exec;
	char	*path;
	char	**cmdline;

	cmdline = get_cmd(command);
	path = get_path(data, cmdline);
	if (path)
	{
		exec = execve(path, cmdline, data->envp);
	}
	else
		exec = -1;
	free(path);
	free(cmdline);
	if (ft_strchr(((t_cmd *)command->content)->line, '/'))
		exec_file(data, command);
	if (exec == -1)
	{
		print_error(((t_cmd *)command->content)->line, \
			NULL, "command not found");
		free_shell(data);
		close_fd();
		exit(127);
	}
}

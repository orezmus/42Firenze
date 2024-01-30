/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:15:41 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 19:00:22 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_cmd(t_list *command)
{
	int		i;
	char	**cmdline;

	cmdline = (char **)malloc(sizeof(char *) * 256);
	i = 0;
	cmdline[i++] = ((t_cmd *)command->content)->line;
	while (command->next && ((t_cmd *)command->next->content)->type > PIPE)
	{
		command = command->next;
		cmdline[i++] = ((t_cmd *)command->content)->line;
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

char	*get_path(t_data *data, char *cmdline)
{
	char	*temp;
	char	**temp_path;
	char	*path;

	temp = extract_envp(&data, "PATH");
	temp_path = ft_split(temp, ':');
	free(temp);
	if (temp_path == NULL)
	{
		close_fd();
		print_error(cmdline, NULL, "No such file or directory");
		exit(127);
	}
	if (ft_strchr(cmdline, '/'))
		return (ft_strdup(cmdline));
	temp = ft_strjoin("/", cmdline);
	path = path_info(temp_path, temp);
	return (path);
}

static void	exec_file(t_data *data, t_list *command)
{
	char			*cmdline[2];
	struct stat		st;

	cmdline[0] = ((t_cmd *)command->content)->line;
	cmdline[1] = NULL;
	if (!stat(cmdline[0], &st) && S_ISREG(st.st_mode))
	{
		if (!(st.st_mode & S_IXUSR))
		{
			print_error(cmdline[0], NULL, "Permission denied.");
			exit(126);
		}
		if (execve(cmdline[0], cmdline, data->envp) == -1)
			exit(127);
	}
	else if (!stat(cmdline[0], &st) && S_ISDIR(st.st_mode))
	{
		print_msg(2, cmdline[0]);
		exit(126);
	}
	else
	{
		print_error(cmdline[0], NULL, "No such file or directory.");
		exit(127);
	}
}

void	exec_cmd(t_data *data, t_list *command)
{
	int		exec;
	char	*path;
	char	**cmdline;

	cmdline = get_cmd(command);
	path = get_path(data, cmdline[0]);
	if (path)
		exec = execve(path, cmdline, data->envp);
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
		close_fd();
		exit(127);
	}
}

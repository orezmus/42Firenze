/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:27 by sum               #+#    #+#             */
/*   Updated: 2024/01/26 13:02:18 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

int		g_exit_status = 0;

static void	print_prompt(char **line)
{
	*line = readline("\033[34;1mbunnyfox$\033[0m ");
	if (*line == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
	else if (**line)
		add_history(*line);
}


int	envp_len(char **envp)
{
	int	i;
	
	i = 0;
	while (envp[i])
		i++;
	return (i);
}


static void	alloc_envp(t_data **data, int argc, char **argv, char **envp)
{
	int	i;
	
	(*data)->command = 0;
	(*data)->argc = argc;
	(*data)->argv = (char **)malloc(sizeof(char *) * 1024);
	i = -1;
	while (++i < argc)
		(*data)->argv[i] = ft_strdup(argv[i]);
	(*data)->argv[i] = NULL;
	(*data)->envp = (char **)malloc(sizeof(char *) * 1024);
	i = -1;
	while (++i < envp_len(envp))
		(*data)->envp[i] = ft_strdup(envp[i]);
	(*data)->envp[i] = NULL;

}

void	init_execute(t_data **data)
{
	t_list	*current;
	
	current = (*data)->command;
	(*data)->fork = 0;
	(*data)->arg = 1;
	(*data)->flag = 1;
	while (current)
	{
		if (((t_cmd *)current->content)->type == PIPE)
			(*data)->arg++;
		current = current->next;
	}
}


void	exec_builtin(t_data *data, t_list *command)
{
	char	*builtin;

	builtin = ((t_cmd *)command->content)->line;
	if (!ft_strcmp(builtin, "cd"))
		ft_cd(data, command);
	else if (!ft_strcmp(builtin, "echo"))
		ft_echo(command);
	else if (!ft_strcmp(builtin, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(builtin, "env"))
		ft_env(command, data->envp);
	else if (!ft_strcmp(builtin, "export"))
		ft_export(data, command);
	else if (!ft_strcmp(builtin, "unset"))
		ft_unset(data, command);
	else if (!ft_strcmp(builtin, "exit"))
		ft_exit(data, command);

}

char	**get_cmd(t_list *command)
{
	int	i;
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

char	*get_path(char **envp, char *cmdline)
{
	char	*temp;
	char	**temp_path;
	char	*path;
	int	i;
		
	i = -1;
	while (envp[++i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			temp_path = ft_split(temp, ':');
			free(temp);
		}
	}
	i = -1;
	while(temp_path[++i])
	{
		temp = ft_strjoin("/", cmdline);
		path = ft_strjoin(temp_path[i], temp);
		free(temp);
		if (open(path, O_RDONLY) == -1)
			free(path);
		else
		{
			while(temp_path[++i])
				free(temp_path[i]);
			free(temp_path);
			return (path);
		}
	}
	i = -1;
	while(temp_path[++i])
		free(temp_path[i]);
	free(temp_path);
	return(NULL);
}


static void	exec_file(t_data *data, t_list *command)
{
	char	*cmdline[2];
	struct stat st;
	t_cmd	*cmd;
	
	cmd = (t_cmd *)command->content;
	cmdline[0] =cmd->line;
	cmdline[1] = NULL;
	if (!stat(cmd->line, &st))
	{
		if (S_ISREG(st.st_mode))
		{
			if (!(st.st_mode & S_IXUSR))
			{
				print_msg(3, cmd->line, "Permission denied.\n");
				exit(126);
			}
			if (execve(cmd->line, cmdline, data->envp) == -1)
				exit(127);
		}
		else if (S_ISDIR(st.st_mode))
		{
			print_msg(2, cmd->line, NULL);
			exit(126);
		}
	}
	else
	{
		print_msg(3, cmd->line, "No such file or directory.\n");
		exit(127);
	}
}
			
void	exec_cmd(t_data *data, t_list *command)
{
	int	exec;
	char	*path;
	char	**cmdline;
	
	cmdline = get_cmd(command);
	path = get_path(data->envp, cmdline[0]);
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
		print_msg(3, ((t_cmd *)command->content)->line, "command not found\n");
		exit(127);
	}
}

void	exec_list(t_data *data, t_list *command)
{
	if (((t_cmd*)command->content)->type == CMD)
		exec_cmd(data, command);
	exit(0);
}

void	exec_child(t_data *data, t_list *command)
{
	if (data->flag < data->arg) //&& data->redir_out == 0
	{
		dup2(data->fd[1][1], STDOUT_FILENO);
		close(data->fd[1][0]);
		close(data->fd[1][1]);
	}
	if (data->flag != 1) //&& data->here_doc[0] == 0
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
	// if (data->here_doc[0] != 0)
	// {
	// 	dup2(data->here_doc[0], STDIN_FILENO);
	// 	close(data->here_doc[0]);
	// }
	exec_list(data, command);
	
}

void	exec_fork(t_data *data, t_list *command)
{
	pid_t	pid;

	data->fork = 1;
	pid = fork();
	if (pid == 0)
	{
		if (data->exit_status == 1 && data->fd[2][0] == -1 && data->arg == 1)
			exit(1);
		exec_child(data, command);
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

void	here_doc(t_data *data, t_list *command)
{
	char	*line;
	pid_t	pid;
	t_cmd	*cmd;
	char	*temp;
	
	cmd = (t_cmd *)command->content;
	pid = fork();
	exit_child(pid);
	signal(SIGINT, heredoc_handle_signal);
	if (pid == 0)
	{
		data->fd[2][0] = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		while (1)
		{
			write(1, "> ", 2);
			line = get_next_line(0);
			if (line == NULL)
				exit(0);
			temp = ft_strtrim(line, "\n");
			free(line);
			if (!ft_strcmp(temp, cmd->line))
			{
				free(temp);
				exit(0);
			}
			ft_putendl_fd(temp, data->fd[2][0]);
			free(temp);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		if (data->exit_status != 1)
			data->fd[2][0] = open(".heredoc", O_RDONLY);
		else
			data->fd[2][0] = -1;
	}
}
		
void	redir_in(t_data *data, t_list *command)
{
	t_cmd	*cmd;
	
	cmd = (t_cmd *)command->content;
	data->fd[2][0] = open(cmd->line, O_RDONLY);
	if (data->fd[2][0] == -1)
	{
		print_msg(3, cmd->line, strerror(errno));
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
		print_msg(3, cmd->line, strerror(errno));
		exit_status(NULL, 1);
	}
}

void	write_here_doc(t_data *data, t_list *command)
{
	char	*line;
	pid_t	pid;
	t_cmd	*cmd;
	char	*temp;
	
	signal(SIGINT, heredoc_handle_signal);
	cmd = (t_cmd *)command->content;
	pid = fork();
	exit_child(pid);
	if (pid == 0)
	{
		data->fd[2][0] = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		while (1)
		{
			write(1, "> ", 2);
			line = get_next_line(0);
			if (line == NULL)
				exit(0);
			temp = ft_strtrim(line, "\n");
			free(line);
			if (!ft_strcmp(temp, cmd->line))
			{
				free(temp);
				exit(0);
			}
			ft_putendl_fd(temp, data->fd[2][0]);
			free(temp);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		if (data->exit_status == 1)
			data->fd[2][0] = -1;
	}
		
}

int	exec_heredoc(t_data *data, t_list *command)
{
	t_cmd	*cmd;

	data->fd[2][0] = 0;
	while (command->next)
	{
		cmd = (t_cmd *)command->content;
		if (cmd->type == HEREDOC)
			write_here_doc(data, command->next);
		if (data->fd[2][0] == -1)
			return (0);
		command = command->next;
	}
	return (1);
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


void	fd_backup(t_data *data, int *stdin, int *stdout)
{
	data->fd[0][0] = data->fd[1][0];
	data->fd[0][1] = data->fd[1][1];
	dup2(*stdin, STDIN_FILENO);
	dup2(*stdout, STDOUT_FILENO);
	close(*stdin);
	close(*stdout);
	data->flag++;
}

void	execute(t_data *data)
{
	int		status;
	t_list	*current;
	//t_cmd	*cmd;
	int		stdin;
	int		stdout;
	
	init_execute(&data);
	current = data->command;
	while (current)
	{
		stdin = dup(STDIN_FILENO);
		stdout = dup(STDOUT_FILENO);
		//cmd = (t_cmd *)current->content;
		if (data->arg > 1)
			pipe(data->fd[1]);
		exec_redir(data, current);
		if (data->exit_status != 1 || data->fd[2][0] != -1)
			exec_fork(data, current);
		fd_backup(data, &stdin, &stdout);
		while (current->next && ((t_cmd *)current->content)->type != PIPE)
			current = current->next;
		current = current->next;
	}
	//if (data->fork)
	//{
		while (waitpid(-1, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				g_exit_status = WEXITSTATUS(status);
		}
	//}

}
	

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	*data;
	t_list	*command;
	t_cmd	*cmd;
	
	data = malloc(sizeof(t_data));
	alloc_envp(&data, argc, argv, envp);
	//print_logo();
	while (1)
	{
		data->exit_status = 0;
		exit_status(&data->exit_status, 0);
		set_signal();
		print_prompt(&line);
		if (!parsing(&data, line) || !update_arg(&data)) //|| !exec_heredoc(data, data->command)
			continue;
		execute(data);
		if (data->command)
		{
			command = data->command;
			while (command)
			{
				cmd = ((t_cmd *)command->content);
				printf("test : type %d, line %s\n", cmd->type, cmd->line);
				command = command->next;
			}
		}
		unlink(".heredoc");
		free_list(data);
	}
	return (0);
}

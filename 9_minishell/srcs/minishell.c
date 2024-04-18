/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:27 by sum               #+#    #+#             */
/*   Updated: 2024/01/30 18:28:39 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	unlink_heredoc(t_data *data)
{
	int		i;
	char	*temp;
	char	*itoa;

	i = -1;
	while (++i < data->heredoc[0])
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin(".heredoc_", itoa);
		unlink(temp);
		free(itoa);
		free(temp);
	}
}

void	close_fd(void)
{
	int	fd;

	fd = 2;
	while (++fd < 1024)
		close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	*data;

	data = malloc(sizeof(t_data));
	alloc_envp(&data, argc, argv, envp);
	data->exit_status = 0;
	exit_status(&data->exit_status, 0);
	set_signal();
	while (1)
	{
		print_prompt(&line);
		if (parsing(&data, line) || update_arg(&data)
			|| exec_heredoc(data, data->command))
		{
			free(line);
			free_list(data);
			continue ;
		}
		free(line);
		execute(data);
		unlink_heredoc(data);
		close_fd();
		free_list(data);
	}
	return (0);
}

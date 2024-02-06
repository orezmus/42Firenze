/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:29:28 by sum               #+#    #+#             */
/*   Updated: 2024/02/02 14:38:19 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	file_non_regular(t_data *data, char *cmdline[2], struct stat st)
{
	if (!stat(cmdline[0], &st) && S_ISDIR(st.st_mode))
	{
		print_msg(2, cmdline[0]);
		free_shell(data);
		exit(126);
	}
	else
	{
		print_error(cmdline[0], NULL, "No such file or directory.");
		free_shell(data);
		exit(127);
	}
}

void	exec_file(t_data *data, t_list *command)
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
			free_shell(data);
			exit(126);
		}
		if (execve(cmdline[0], cmdline, data->envp) == -1)
		{
			free_shell(data);
			exit(127);
		}
	}
}

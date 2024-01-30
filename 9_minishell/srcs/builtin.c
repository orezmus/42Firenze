/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:33:49 by femorell          #+#    #+#             */
/*   Updated: 2024/01/29 17:58:41 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(t_data *data, t_list *command)
{
	char	*builtin;

	builtin = ((t_cmd *)command->content)->line;
	if (!ft_strcmp(builtin, "exit"))
		ft_exit(data, command);
	else if (!ft_strcmp(builtin, "cd"))
		ft_cd(data, command);
	else if (!ft_strcmp(builtin, "export"))
		ft_export(data, command);
	else if (!ft_strcmp(builtin, "unset") && data->arg == 1)
		ft_unset(data, command);
}

void	exec_fork_builtin(t_data *data, t_list *command)
{
	char	*builtin;

	builtin = ((t_cmd *)command->content)->line;
	if (!ft_strcmp(builtin, "echo"))
		ft_echo(command);
	else if (!ft_strcmp(builtin, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(builtin, "env"))
		ft_env(command, data->envp);
}

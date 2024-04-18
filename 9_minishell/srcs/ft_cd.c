/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:35 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 14:08:26 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd_home(char *home)
{
	if (home == NULL)
	{
		print_error("cd", NULL, "HOME not set");
		return (1);
	}
	if (!*home)
		return (1);
	if ((chdir(home) < 0))
	{
		print_error("cd", NULL, strerror(errno));
		return (1);
	}
	return (0);
}

int	ft_cd_tilde(t_data *data, char *path, char *home)
{
	int		rt;

	rt = 0;
	if (home == NULL)
		rt = no_home(data, path);
	else
		rt = exist_home(path, home);
	return (rt);
}

int	ft_cd_old(t_data *data)
{
	char	*oldpwd;
	char	buf[1024];

	oldpwd = extract_envp(&data, "OLDPWD");
	if (oldpwd == NULL)
	{
		print_error("cd", NULL, "OLDPWD not set");
		free(oldpwd);
		return (1);
	}
	if (chdir(oldpwd) < 0)
	{
		print_error("cd", NULL, strerror(errno));
		free(oldpwd);
		return (1);
	}
	ft_putendl_fd(getcwd(buf, 1024), 1);
	free(oldpwd);
	return (0);
}

int	ft_cd_dir(t_data *data, t_list *command)
{
	char	**path;
	t_cmd	*cmd_next;

	cmd_next = (t_cmd *)command->next->content;
	if (extract_envp(&data, "CDPATH") != NULL && *(cmd_next->line) != '/')
	{
		path = put_slash(data);
		if (ft_cd_path(command, path) > 0)
			return (1);
	}
	else
	{
		if (cmd_next->type != PIPE && chdir(cmd_next->line) < 0)
		{
			print_error("cd", cmd_next->line, strerror(errno));
			return (1);
		}
	}
	return (0);
}

void	ft_cd(t_data *data, t_list *command)
{
	char	*oldpwd;
	char	*path;
	int		rt;

	path = extract_envp(&data, "HOME");
	oldpwd = extract_envp(&data, "PWD");
	rt = 0;
	if (!command->next)
		rt = ft_cd_home(path);
	else if (!ft_strncmp(((t_cmd *)command->next->content)->line, "~", 1))
		rt = ft_cd_tilde(data, ((t_cmd *)command->next->content)->line, path);
	else if (!ft_strncmp(((t_cmd *)command->next->content)->line, "-", 1))
		rt = ft_cd_old(data);
	else
		rt = ft_cd_dir(data, command);
	free(path);
	if (rt > 0)
		exit_status(NULL, 1);
	else
		exit_status(NULL, 0);
	update_oldpwd(data, oldpwd);
	update_pwd(data);
}

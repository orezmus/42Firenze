/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:35 by femorell          #+#    #+#             */
/*   Updated: 2024/01/26 11:09:42 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	no_home(t_data *data)
{
	char	*user_home;
	char	*log_name;

	log_name = extract_envp("USERNAME", &data);
	user_home = ft_strjoin("/home/", log_name);
	if (chdir(user_home) < 0)
	{
			print_msg(3, "cd", strerror(errno));
			free(user_home);
			free(log_name);
			return (1);
	}
	free(user_home);
	free(log_name);
	return (0);
}

int	ft_cd_home(char *home)
{
	if (home == NULL)
	{
		print_msg(3, "cd", "HOME not set");
		return (1);
	}
	if (!*home)
		return (1);
	if ((chdir(home) < 0))
	{
		print_msg(3, "cd", strerror(errno));
		return (1);
	}
	return (0);
}

int	ft_cd_tilde(t_data *data, char *home)
{
 	int	rt;

	rt = 0;
	if (home == NULL)
	{
		rt = no_home(data);
		return (rt);
	}
	else
	{
		if (*home && (chdir(home) < 0))
		{
			print_msg(3, "cd", strerror(errno));
			return (1);
		}
	}
	return (0);
}
int	ft_cd_old(t_data *data)
{
	char	*oldpwd;
	char	buf[1024];
	
	oldpwd = extract_envp("OLDPWD", &data);
	if (oldpwd == NULL)
	{
		ft_putstr_fd("bunnyfox: cd: OLDPWD not set\n", 2);
		free(oldpwd);
		return (1);
	}
	if (chdir(oldpwd) < 0)
	{
		print_msg(3, "cd", strerror(errno));
		free(oldpwd);
		return (1);
	}
	ft_putendl_fd(getcwd(buf, 1024), 1);
	free(oldpwd);
	return (0);
}

int	ft_cd_dir(t_data *data, t_list *command)
{
	//char	**path;

	if (extract_envp("CDPATH", &data) != NULL && *(((t_cmd*)command->next->content)->line) != '/')
	{
		printf("hell\n");
		// path = put_slash();
		// if (ft_cd_path(path, command) > 0)
		// 	return (1);
	}
	else
	{
		if (chdir(((t_cmd*)command->next->content)->line) < 0)
		{
			print_msg(3, "cd", strerror(errno));
			return (1);
		}
	}
	return (0);
}

void	ft_cd(t_data *data, t_list *command)
{
	char	*path;
	int	rt;
	t_cmd	*cmd_next;
	
	path = extract_envp("HOME", &data);
	rt = 0;
	if (!command->next)
	{
		printf("hoe : %s\n", path);
		rt = ft_cd_home(path);
	}
	else
	{	
		cmd_next = (t_cmd*)command->next->content;
		if (!ft_strcmp(cmd_next->line, "~"))
			rt = ft_cd_tilde(data, path);
		else if (!ft_strcmp(cmd_next->line, "-"))
			rt = ft_cd_old(data);
		else
			rt = ft_cd_dir(data, command);
	}
	free(path);
	if (rt > 0)
		printf("0\n");
}
	

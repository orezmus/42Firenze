/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:00:21 by sum               #+#    #+#             */
/*   Updated: 2024/01/30 14:08:41 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd_path(t_list *command, char **cd_path)
{
	char	*temp;
	char	buf[1024];
	int		i;

	i = -1;
	while (cd_path[++i])
	{
		temp = ft_strjoin(cd_path[i], ((t_cmd *)command->next->content)->line);
		if (!chdir(temp))
		{
			ft_putendl_fd(getcwd(buf, 1024), 1);
			free_split(cd_path);
			free(temp);
			return (0);
		}
		free(temp);
	}
	print_error("cd", NULL, strerror(errno));
	free_split(cd_path);
	return (1);
}

char	**put_slash(t_data *data)
{
	char	**cd_path;
	char	*temp;
	int		i;
	int		j;

	temp = extract_envp(&data, "CDPATH");
	cd_path = ft_split(temp, ':');
	free(temp);
	i = -1;
	while (cd_path[++i])
	{
		j = 0;
		while (cd_path[i][j])
			j++;
		if (cd_path[i][--j] != '/')
		{
			temp = cd_path[i];
			cd_path[i] = ft_strjoin(cd_path[i], "/");
			free(temp);
		}
	}
	return (cd_path);
}

void	update_pwd(t_data *data)
{
	int		i;
	char	*pwd;
	char	*temp;

	i = find_key(data, "PWD=");
	pwd = getcwd(0, 1024);
	if (i < envp_len(data->envp))
	{
		temp = data->envp[find_key(data, "PWD=")];
		data->envp[i] = ft_strjoin("PWD=", pwd);
		free(temp);
	}
	free(pwd);
}

void	update_oldpwd(t_data *data, char *path)
{
	int		i;
	char	*oldpwd;

	i = find_key(data, "OLDPWD=");
	if (path == NULL)
		data->envp[i] = strdup("");
	else if (i < envp_len(data->envp))
	{
		oldpwd = data->envp[i];
		data->envp[i] = ft_strjoin("OLDPWD=", path);
		free(oldpwd);
	}
	else
	{
		data->envp[i] = ft_strjoin("OLDPWD=", path);
		data->envp[++i] = NULL;
	}
	free(path);
}

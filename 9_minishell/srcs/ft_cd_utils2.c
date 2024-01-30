/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:02:15 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 18:34:38 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exist_home(char *path, char *home)
{
	char	*temp;

	if (!ft_strcmp(path, "~"))
	{
		if (*home && (chdir(home) < 0))
		{
			print_error("cd", NULL, strerror(errno));
			return (1);
		}
	}
	else
	{
		while (*path == '~' || *path == '/')
			path++;
		path--;
		temp = ft_strjoin(home, path);
		if (*temp && (chdir(temp) < 0))
		{
			print_error("cd", path, strerror(errno));
			free(temp);
			return (1);
		}
		free(temp);
	}
	return (0);
}

int	no_home(t_data *data, char *path)
{
	char	*user_home;
	char	*temp;

	user_home = extract_envp(&data, "USER");
	temp = ft_strjoin("/nfs/homes/", user_home);
	free(user_home);
	if (!ft_strcmp(path, "~"))
		user_home = ft_strdup(temp);
	else
	{
		while (*path == '~' || *path == '/')
			path++;
		path--;
		user_home = ft_strjoin(temp, path);
	}
	if (chdir(user_home) < 0)
	{
		print_error("cd", NULL, strerror(errno));
		free(user_home);
		free(temp);
		return (1);
	}
	free(user_home);
	free(temp);
	return (0);
}

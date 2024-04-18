/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:48:00 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 13:46:26 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_key(t_data *data, char *key)
{
	int	i;

	i = -1;
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], key, ft_strlen(key)) == 0)
			break ;
	}
	return (i);
}

int	envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	*extract_envp(t_data **data, char *line)
{
	int		i;
	char	*rt;
	char	*new;
	char	**temp;

	new = ft_strjoin(line, "=");
	i = -1;
	rt = NULL;
	while ((*data)->envp[++i])
	{
		if (!ft_strncmp((*data)->envp[i], new, ft_strlen(new)))
		{
			temp = ft_split((*data)->envp[i], '=');
			if (temp[1])
				rt = ft_strdup(temp[1]);
			else
				rt = ft_strdup("");
			free(new);
			free_split(temp);
			return (rt);
		}
	}
	free(new);
	return (rt);
}

void	alloc_envp(t_data **data, int argc, char **argv, char **envp)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:12:19 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 22:39:11 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_export(t_data *data)
{
	int		i;
	char	**split;

	i = -1;
	while (data->envp[++i] != NULL)
	{
		printf("declare -x ");
		split = ft_split(data->envp[i], '=');
		if (split[1])
			printf("%s=\"%s\"\n", split[0], split[1]);
		else
			printf("%s=\"\"\n", split[0]);
		free_split(split);
	}
}

int	valid_key(char *key)
{
	int	i;

	i = 1;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while (key[i] && key[i] != '=')
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	update_envp(t_data *data, t_list *command, char *key, int i)
{
	char	*temp;
	t_cmd	*cmd_next;

	if (command->next)
		cmd_next = (t_cmd *)command->next->content;
	if (i < envp_len(data->envp))
	{
		temp = data->envp[i];
		if (command->next == NULL || cmd_next->type == ARG)
			data->envp[i] = ft_strjoin(((t_cmd *)command->content)->line, "");
		else if (cmd_next->type == DQUOTE)
			data->envp[i] = ft_strjoin(key, cmd_next->line);
		free(temp);
	}
	else
	{
		if (command->next == NULL || cmd_next->type == ARG)
			data->envp[i] = ft_strjoin(((t_cmd *)command->content)->line, "");
		else if (cmd_next->type == DQUOTE)
			data->envp[i] = ft_strjoin(key, cmd_next->line);
		data->envp[++i] = NULL;
	}
}

void	update_env(t_data *data, t_list *command)
{
	int		i;
	char	*new;
	char	**split;
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	if (ft_strchr(cmd->line, '='))
	{
		if (command->next == NULL
			|| ((t_cmd *)command->next->content)->type == ARG)
		{
			split = ft_split(cmd->line, '=');
			new = ft_strjoin(split[0], "=");
			free_split(split);
		}
		else
			new = ft_strdup(cmd->line);
		i = find_key(data, new);
		update_envp(data, command, new, i);
		free(new);
	}
}

void	ft_export(t_data *data, t_list *command)
{
	t_list	*current;

	current = command;
	if (!current->next || ((t_cmd *)current->next->content)->type <= PIPE)
		print_export(data);
	else
	{
		current = current->next;
		while (current && ((t_cmd *)current->content)->type > PIPE)
		{
			if (((t_cmd *)current->content)->type != DQUOTE
				&& !valid_key(((t_cmd *)current->content)->line))
			{
				print_error("export", ((t_cmd *)current->content)->line, \
					"not a valid identifier");
				exit_status(NULL, 1);
			}
			else if (((t_cmd *)current->content)->type != DQUOTE)
				update_env(data, current);
			current = current->next;
		}
	}
	exit_status(NULL, 0);
}

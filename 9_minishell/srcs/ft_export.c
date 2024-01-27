/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:12:19 by sum               #+#    #+#             */
/*   Updated: 2024/01/26 11:20:11 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	print_export(t_data *data)
{
	int	i;
	//char	**temp;
	char 	**split;
	
	i = -1;
	while (data->envp[++i])
	{
		printf("declare -x ");
		split = ft_split(data->envp[i], '=');
		if (split[1])
			printf("%s=\"%s\"\n", split[0], split[1]);
		else
			printf("%s=\"\"\n", split[0]);
		free(split[0]);
		free(split[1]);
	}
}
	
int	valid_key(char *key)
{
	int i;

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
	
	if (i < envp_len(data->envp))
	{
		temp = data->envp[i];
		if (!command || ((t_cmd *)command->content)->type == ARG)
			data->envp[i] = ft_strjoin(key, "");
		else if (((t_cmd *)command->content)->type == DQUOTE)
			data->envp[i] = ft_strjoin(key, ((t_cmd *)command->content)->line);
		free(temp);
	}
	else
	{
		if (!command || ((t_cmd *)command->content)->type == ARG)
			data->envp[i] = ft_strjoin(key, "");
		else if (((t_cmd *)command->content)->type == DQUOTE)
			data->envp[i] = ft_strjoin(key, ((t_cmd *)command->content)->line);
		data->envp[++i] = NULL;
	}
}

void	update_env(t_data *data, t_list *command)
{
	int	i;
	char *new;
	t_cmd	*cmd;
	
	i = -1;
	cmd = (t_cmd *)command->content;
	if (ft_strchr(cmd->line, '='))
	{
		new = cmd->line;
		while (data->envp[++i])
		{
			printf("%s\n", cmd->line);
			if (ft_strncmp(data->envp[i], new, ft_strlen(new)) == 0)
				break ;
		}
		update_envp(data, command->next, new, i);
	}
			
}

void	ft_export(t_data *data, t_list *command)
{
	t_list  *current;

	current = command;
	if (!current->next || ((t_cmd *)current->next->content)->type <= PIPE)
		print_export(data);
	else
	{
		current = current->next;
		while (current && ((t_cmd *)current->content)->type > PIPE)
		{
			if (((t_cmd*)current->content)->type != DQUOTE)
			{
				if (!valid_key(((t_cmd *)current->content)->line))
				{
				    print_msg(3, "export", "not a valid identifier.\n");
				    g_exit_status = 1;
				    exit (1);
				}
			else
				update_env(data, current);
		}
		current = current->next;
		}
	}
	//exit (0);
}

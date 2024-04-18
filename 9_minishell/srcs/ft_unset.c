/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:03:30 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 23:11:29 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_envp(t_data *data, char *key)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(key, "=");
	i = find_key(data, temp);
	free(temp);
	if (i < envp_len(data->envp))
	{
		temp = data->envp[i];
		data->envp[i] = ft_strdup("");
		free(temp);
	}
}

void	ft_unset(t_data *data, t_list *command)
{
	if (command->next)
		command = command->next;
	while (command && ((t_cmd *)command->content)->type > PIPE)
	{
		if (!valid_key(((t_cmd *)command->content)->line)
			|| ft_strchr(((t_cmd *)command->content)->line, '='))
		{
			print_error("unset", ((t_cmd *)command->content)->line,
				"not a valid identifier");
			exit_status(NULL, 1);
		}
		else
			delete_envp(data, ((t_cmd *)command->content)->line);
		command = command->next;
	}
}

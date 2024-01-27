/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:03:30 by sum               #+#    #+#             */
/*   Updated: 2024/01/26 13:03:32 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_envp(t_data *data, char *key)
{
	int	i;
	char	*temp;
	
	i = -1;
	temp = ft_strjoin(key, "=");
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], temp, ft_strlen(temp)) == 0)
			break;
	}
	free(temp);
	if (i < envp_len(data->envp))
	{
		temp = data->envp[i];
		data->envp[i]= ft_strdup("");
		free(temp);
	}
}

void	ft_unset(t_data *data, t_list *command)
{
	if (command->next)
		command = command->next;
	while (command && ((t_cmd*)command->content)->type > PIPE)
	{
		if (!valid_key(((t_cmd*)command->content)->line))
		{
		    print_msg(3, "unset", "not a valid identifier.\n");
		    g_exit_status = 1;
		    exit (1);
		}
		else
			delete_envp(data, ((t_cmd*)command->content)->line);
		command = command->next;
	}
	//exit (0);
}

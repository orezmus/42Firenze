/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:39:02 by femorell          #+#    #+#             */
/*   Updated: 2024/01/29 18:42:02 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_list(t_data *data)
{
	t_list	*current;
	t_list	*next;

	current = data->command;
	while (current != NULL)
	{
		next = current->next;
		if (current->content != NULL)
		{
			free(((t_cmd *)current->content)->line);
			free(current->content);
		}
		free(current);
		current = next;
	}
	data->command = NULL;
}

void	add_list(t_data **data, char *line, int type)
{
	t_cmd	*cmd;

	cmd = init_cmd();
	cmd->type = type;
	cmd->line = line;
	if ((*data)->command == 0)
		(*data)->command = ft_lstnew(cmd);
	else
		ft_lstadd_back(&(*data)->command, ft_lstnew(cmd));
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = -1;
	cmd->line = NULL;
	return (cmd);
}

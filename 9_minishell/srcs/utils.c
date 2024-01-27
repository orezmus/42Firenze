/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:18:00 by sum               #+#    #+#             */
/*   Updated: 2024/01/26 00:36:52 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_status(int *exit, int code)
{
	static int	*exit_status;

	if (exit)
		exit_status = exit;
	*exit_status = code;
}

void	print_msg(int sign, char *str, char *msg)
{
	ft_putstr_fd("bunnyfox: ", 2);
	if (sign == 1)
	{
		ft_putstr_fd("syntax error near unexpected token", 2);
		if (!ft_strcmp(msg, " `|'\n"))
			ft_putstr_fd(msg, 2);
		else if (!ft_strcmp(msg, " `newline'\n"))
			ft_putstr_fd(msg, 2);
		else
		{
			ft_putstr_fd(" `", 2);
			ft_putstr_fd(msg, 2);
			ft_putstr_fd("'\n", 2);
		}
	}
	else if (sign == 2)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": Is a Directory\n", 2);
	}
	else
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}	
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = -1;
	cmd->line = NULL; //ft_strdup("");
	return (cmd);
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

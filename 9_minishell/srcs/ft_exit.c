/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:18:58 by sum               #+#    #+#             */
/*   Updated: 2024/02/03 12:56:10 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_num(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void
	exit_error(t_data *data, char *str)
{
	if (data->arg == 1)
		printf("exit\n");
	if (str[0] == '|')
		return ;
	print_error("exit", str, "numeric argument required");
	if (data->arg == 1)
	{
		free_shell(data);
		close_fd();
		exit(255);
	}
}

void	ft_exit_arg(t_data *data, t_list *command)
{
	int		rt;
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	if (!is_num(cmd->line))
		exit_error(data, cmd->line);
	else
	{
		if (data->arg == 1)
			printf("exit\n");
		if (!command->next)
		{
			rt = ft_atoi(((t_cmd *)command->content)->line);
			exit_status(NULL, (rt & 255));
			free_shell(data);
			close_fd();
			exit(rt & 255);
		}
		else if (data->arg == 1)
		{
			exit_status(NULL, 1);
			data->fork = 0;
			print_error("exit", NULL, "too many arguments");
		}
	}
}

void	ft_exit(t_data *data, t_list *command)
{
	if (command->next && ((t_cmd *)command->next->content)->line[0] == 0)
		command = command->next;
	if (!command->next)
	{
		printf("exit\n");
		free_shell(data);
		close_fd();
		exit(0);
	}
	else
		ft_exit_arg(data, command->next);
}

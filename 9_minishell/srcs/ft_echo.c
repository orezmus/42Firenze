/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:15:54 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 13:53:53 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_echo_no_nl(t_list *command)
{
	if (!command->next && ((t_cmd *)command->next->content)->type > PIPE)
		return (0);
	else
	{
		command = command->next;
		while (command && ((t_cmd *)command->content)->type > PIPE)
		{
			ft_putstr_fd(((t_cmd *)command->content)->line, 1);
			if (command->next)
				ft_putstr_fd(" ", 1);
			command = command->next;
		}
	}
	return (0);
}

int	ft_echo_arg(t_list *command)
{
	while (command && ((t_cmd *)command->content)->type > PIPE)
	{
		printf("%s", ((t_cmd *)command->content)->line);
		if (command->next)
			printf(" ");
		command = command->next;
	}
	printf("\n");
	return (0);
}

int	check_nl(char *line)
{
	int	i;

	i = -1;
	if (line[++i] != '-')
		return (0);
	while (line[++i])
	{
		if (line[i] != 'n')
			break ;
	}
	if (i != ft_strlen(line))
		return (0);
	return (1);
}

void	ft_echo(t_list *command)
{
	if (!command->next || ((t_cmd *)command->next->content)->type <= PIPE)
		write(1, "\n", 1);
	else if (!ft_strncmp(((t_cmd *)command->next->content)->line, "-n", 2))
	{
		while (check_nl(((t_cmd *)command->next->content)->line))
			command = command->next;
		ft_echo_no_nl(command);
	}
	else
	{
		command = command->next;
		ft_echo_arg(command);
	}
	exit_status(NULL, 0);
}

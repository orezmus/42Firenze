/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:16:14 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 13:54:18 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_list *command, char **envp)
{
	int	i;

	if (command->next && ((t_cmd *)command->next->content)->type == ARG)
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(((t_cmd *)command->next->content)->line, 2);
		ft_putstr_fd("': No such file or directory\n", 2);
		exit_status(NULL, 1);
		exit(1);
	}
	i = -1;
	while (envp[++i])
	{
		if (ft_strchr(envp[i], '='))
		{
			write(STDOUT, envp[i], ft_strlen(envp[i]));
			write(STDOUT, "\n", 1);
			exit_status(NULL, 0);
		}
	}
}

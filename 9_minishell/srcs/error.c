/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:20 by femorell          #+#    #+#             */
/*   Updated: 2024/01/29 18:23:15 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_msg(int sign, char *msg)
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
	else
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": Is a Directory\n", 2);
	}
}

void	print_error(char *cmd, char *str, char *msg)
{
	ft_putstr_fd("bunnyfox: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset"))
	{
		ft_putstr_fd("'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("' ", 2);
		ft_putstr_fd(": ", 2);
	}
	else if (str != NULL)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

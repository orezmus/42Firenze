/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:32:31 by sum               #+#    #+#             */
/*   Updated: 2024/02/03 13:38:30 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_sigint(int pid, int status)
{
	if (pid == -1)
	{
		rl_replace_line("", 1);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		if (!WIFEXITED(status))
			ft_putstr_fd("\n", STDOUT_FILENO);
		exit_status(NULL, 130);
		g_exit = 130;
	}
}

static void	ft_sigquit(int pid, int status)
{
	if (pid == -1)
		ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
	else
	{
		if (!WIFEXITED(status))
		{
			ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
			exit_status(NULL, 131);
		}
	}
}

static void	handle_signal(int signal)
{
	int	pid;
	int	status;

	pid = waitpid(-1, &status, 0);
	if (signal == SIGINT)
		ft_sigint(pid, status);
	else if (signal == SIGQUIT)
		ft_sigquit(pid, status);
}

void	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

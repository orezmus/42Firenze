/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:32:31 by sum               #+#    #+#             */
/*   Updated: 2024/01/25 18:40:53 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_child(int pid)
{
	static int	pid_to_kill;

	if (pid_to_kill)
	{
		write (1, "\n", 1);
		kill(pid_to_kill, SIGKILL);
		pid_to_kill = 0;
		exit_status(NULL, 1);
	}
	else if (pid)
		pid_to_kill = pid;
}

void	heredoc_handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		exit_child(0);
		//g_exit_code = 130;
	}
}

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
}

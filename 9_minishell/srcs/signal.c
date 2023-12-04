/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:32:31 by sum               #+#    #+#             */
/*   Updated: 2023/11/28 12:32:33 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int signo)
{
	pid_t	pid;
	int	status;
	
	pid = waitpid(-1, &status, 0);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			rl_replace_line("", 0);
			printf("\n");
			rl_on_new_line();
			rl_redisplay();
		}
		else 
			ft_putchar_fd('\n', 1);
	}
	else if (signo == SIGQUIT)
	{
		if (pid == -1)
			return ;
	}
}
	
void	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}


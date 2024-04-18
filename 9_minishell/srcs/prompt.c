/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:43:54 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 15:33:05 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_escape(char *str, char *escape_type)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!*escape_type && (str[i] == '\'' || str[i] == '"' || str[i] == '`'))
			*escape_type = str[i];
		else if (*escape_type == str[i])
			*escape_type = 0;
		if (!*escape_type && str[i] == '\\' && !str[i + 1])
			*escape_type = str[i];
		if (!*escape_type && str[i] == '|')
		{
			while (str[i + 1] && ft_isspace(str[i + 1]))
				i++;
			if (!str[i + 1])
				*escape_type = '|';
		}
		i++;
	}
}

void	find_escape(char *str, char *escape_type)
{
	int	i;

	if (*escape_type == '\\')
		*escape_type = 0;
	if (*escape_type == '|')
	{
		i = 0;
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (!str[i] || ft_isspace(str[i]))
			return ;
		if (str[i] == '|')
		{
			*escape_type = 0;
			return ;
		}
		*escape_type = 0;
	}
	update_escape(str, escape_type);
}

void	error_escape(char *escape_type)
{
	if (*escape_type != '\\' && *escape_type != '|')
	{
		ft_putstr_fd("bunnyfox: ", 2);
		ft_putstr_fd("unexpected EOF while looking for matching ", 2);
		ft_putchar_fd(*escape_type, 2);
		ft_putstr_fd("'\n", 2);
	}
	if (*escape_type != '\\')
	{
		print_error("syntax error", NULL, "unexpected end of file");
		if (*escape_type == '|')
		{
			ft_putstr_fd("exit\n", 2);
			exit(2);
		}
	}
	*escape_type = 0;
	exit_status(NULL, 2);
}

void	check_escape(char *next_line, char **input, char escape_type)
{
	escape_quote(next_line, input, escape_type);
	escape_backslash(next_line, input, escape_type);
	escape_pipe(next_line, input, escape_type);
}

void	print_prompt(char **input)
{
	char	*next_line;
	char	escape_type;

	escape_type = 0;
	*input = readline("\033[34;1mbunnyfox$\033[0m ");
	if (!*input)
	{
		printf("exit\n");
		exit(0);
	}
	find_escape(*input, &escape_type);
	while (escape_type)
	{
		next_line = readline("> ");
		if (!next_line)
		{
			error_escape(&escape_type);
			break ;
		}
		check_escape(next_line, input, escape_type);
		find_escape(next_line, &escape_type);
		free(next_line);
	}
	if (**input)
		add_history(*input);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:25:21 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 15:27:56 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	escape_quote(char *next_line, char **input, char escape_type)
{
	char	*temp;

	if (escape_type == '\'' || escape_type == '"' || escape_type == '`')
	{
		temp = *input;
		*input = ft_strjoin(*input, "\n");
		free(temp);
		temp = *input;
		*input = ft_strjoin(*input, next_line);
		free(temp);
	}
}

void	escape_backslash(char *next_line, char **input, char escape_type)
{
	char	*temp;

	if (escape_type == '\\')
	{
		temp = *input;
		*input = ft_substr(*input, 0, ft_strlen(*input) - 1);
		free(temp);
		temp = *input;
		*input = ft_strjoin(*input, next_line);
		free(temp);
	}
}

void	escape_pipe(char *next_line, char **input, char escape_type)
{
	char	*temp;

	if (escape_type == '|' && *next_line)
	{
		temp = *input;
		*input = ft_strjoin(*input, " ");
		free(temp);
		temp = *input;
		*input = ft_strjoin(*input, next_line);
		free(temp);
	}
}

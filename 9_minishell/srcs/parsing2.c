/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:16:01 by sum               #+#    #+#             */
/*   Updated: 2024/02/03 11:10:53 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	extract_meta(int *i, char *line, t_data **data)
{
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		(*i)++;
		add_list(data, ft_strdup("<<"), HEREDOC);
	}
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		(*i)++;
		add_list(data, ft_strdup(">>"), APPEND);
	}
	else if (line[*i] == '<')
		add_list(data, ft_strdup("<"), REDIRIN);
	else if (line[*i] == '>')
		add_list(data, ft_strdup(">"), REDIROUT);
	else if (line[*i] == '|')
		add_list(data, ft_strdup("|"), PIPE);
}

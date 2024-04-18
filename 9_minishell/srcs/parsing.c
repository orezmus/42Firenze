/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:16:01 by sum               #+#    #+#             */
/*   Updated: 2024/01/29 17:42:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_quotes(char *line, char quote, int *i)
{
	int	temp;

	temp = *i;
	while (line[temp])
	{
		if (line[temp] == quote)
			return (0);
		temp++;
	}
	return (1);
}

static int	extract_quote(int *i, char *line, t_data **data)
{
	int		temp;
	char	*new;
	char	quote;

	quote = line[(*i)++];
	if (check_quotes(line, quote, i))
		return (1);
	temp = *i;
	while (line[*i] != quote && line[*i])
		(*i)++;
	new = ft_substr(line, temp, *i - temp);
	if (quote == '\'')
		add_list(data, new, SQUOTE);
	else
	{
		expansion(data, &new);
		if (ft_strcmp(new, ""))
			add_list(data, new, DQUOTE);
	}
	return (0);
}

static void	extract_meta(int *i, char *line, t_data **data)
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

static void	extract_arg(int *i, char *line, t_data **data)
{
	char	*new;
	int		temp;

	temp = *i;
	while (line[*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != '|'
		&& line[*i] != ' ' && line[*i] != '"' && line[*i] != '\''
		&& line[*i] != '\\' && line[*i] != ';')
		(*i)++;
	if (*i - temp)
	{
		new = ft_substr(line, temp, *i - temp);
		expansion(data, &new);
		if (new != NULL)
			add_list(data, new, ARG);
	}
	(*i)--;
}

int	parsing(t_data **data, char *line)
{
	int	i;

	if (!line)
		return (1);
	i = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '"' || line[i] == '\'')
		{
			if (extract_quote(&i, line, &(*data)))
				return (1);
		}
		else if (line[i] == '\\' || line [i] == ';')
			return (1);
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			extract_meta(&i, line, &(*data));
		else
			extract_arg(&i, line, &(*data));
	}
	return (check_syntax(data));
}

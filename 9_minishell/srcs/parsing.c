/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:16:01 by sum               #+#    #+#             */
/*   Updated: 2024/02/03 12:50:39 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*extract_quote(t_data **data, int *i, char *line)
{
	int		temp;
	char	*new;
	char	quote;

	quote = line[(*i)++];
	if (line[*i] == quote)
		return (NULL);
	temp = *i;
	while (line[*i] && line[*i] != quote)
	{
		(*i)++;
	}
	new = ft_substr(line, temp, *i - temp);
	if (quote != '\'')
		expansion(data, &new);
	return (new);
}

static char	*extract_arg(t_data **data, int *i, char *line)
{
	int		temp;
	char	*new;

	temp = *i;
	while (line[*i] && !ft_isspace(line[*i]) && \
		line[*i] != '"' && line[*i] != '\'' && \
		line[*i] != '<' && line[*i] != '>' && line[*i] != '|' && \
		line[*i] != '\\' && line[*i] != ';')
	{
		(*i)++;
	}
	new = ft_substr(line, temp, *i - temp);
	expansion(data, &new);
	(*i)--;
	return (new);
}

static void	extract2(int *i, char **temp, t_data **data)
{
	char	*new;
	char	*tmp2;
	int		j;

	new = ft_strdup("");
	j = -1;
	while (temp[++j])
	{
		tmp2 = new;
		new = ft_strjoin(new, temp[j]);
		free(tmp2);
		free(temp[j]);
	}
	free(temp);
	add_list(data, new, ARG);
	(*i)--;
}

static void	extract(int *i, char *line, t_data **data)
{
	char	**temp;
	int		j;

	temp = malloc(sizeof(char *) * 1000);
	j = 0;
	while (line[*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != '|'
		&& !ft_isspace(line[*i]) && line[*i] != '\\' && line[*i] != ';')
	{
		if (line[*i] == '"' || line[*i] == '\'')
		{
			temp[j++] = extract_quote(data, i, line);
			if (temp[j - 1] == NULL)
				j--;
		}
		else
			temp[j++] = extract_arg(data, i, line);
		(*i)++;
	}
	temp[j] = NULL;
	extract2(i, temp, data);
}

int	parsing(t_data **data, char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i] && (line[i] == '\\' || line [i] == ';'))
			return (1);
		else if (line[i] && \
			(line[i] == '<' || line[i] == '>' || line[i] == '|'))
			extract_meta(&i, line, &(*data));
		else if (line[i])
			extract(&i, line, &(*data));
		if (line[i])
			i++;
	}
	return (check_syntax(data));
}

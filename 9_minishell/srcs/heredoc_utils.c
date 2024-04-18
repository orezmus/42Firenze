/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:28:00 by femorell          #+#    #+#             */
/*   Updated: 2024/01/29 18:31:18 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*update_dollar_heredoc(t_data **data, char *line, int *start)
{
	int		i;
	char	front[256];
	char	back[256];
	char	*rt;

	i = 0;
	while (line[*start] && !ft_isalnum(line[*start]))
		front[i++] = line[(*start)++];
	front[i] = '\0';
	i = 0;
	while (line[*start])
		back[i++] = line[(*start)++];
	back[i] = '\0';
	rt = do_expansion(data, front, back);
	return (rt);
}

void	expansion_heredoc(t_data **data, char **line)
{
	int		i;
	char	*temp;
	char	*env;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '$')
		{
			temp = ft_substr(*line, 0, i);
			i++;
			env = update_dollar_heredoc(data, *line, &i);
			free(*line);
			*line = ft_strjoin(temp, env);
			free(temp);
			free(env);
			i = 0;
		}
		else
			i++;
	}
}

void	strjoin_escape(char **str, char *next_line, bool escape)
{
	char	*temp;

	if (escape == 1)
	{
		temp = *str;
		*str = ft_substr(*str, 0, ft_strlen(*str) - 1);
		free(temp);
		temp = *str;
		*str = ft_strjoin(*str, next_line);
		free(temp);
	}
}

void	check_newline(char *str, bool *escape)
{
	int	i;

	if (*escape == 1)
		*escape = 0;
	i = -1;
	while (str[++i])
	{
		if (*escape == 0 && str[i] == '\\' && !str[i + 1])
			*escape = 1;
	}
}

void	heredoc_nl(char **str)
{
	bool	escape;
	char	*next_line;

	escape = 1;
	check_newline(*str, &escape);
	while (escape)
	{
		next_line = readline("> ");
		if (!next_line)
		{
			escape = 0;
			break ;
		}
		strjoin_escape(str, next_line, escape);
		check_newline(next_line, &escape);
		free(next_line);
	}
}

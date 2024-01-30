/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:28:00 by femorell          #+#    #+#             */
/*   Updated: 2024/01/30 18:12:35 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*do_expansion(t_data **data, char *line, char *back)
{
	char	*temp;
	char	*rt;

	temp = extract_envp(data, line);
	if (temp == NULL)
	{
		if (ft_isdigit(line[0]))
			temp = ft_strdup((*data)->argv[ft_atoi(line)]);
		else if (line[0] == '#')
			temp = ft_itoa((*data)->argc);
		else if (line[0] == '?')
			temp = ft_itoa((*data)->exit_status);
		else
			temp = ft_strdup("");
	}
	rt = ft_strjoin(temp, back);
	free(temp);
	return (rt);
}

int	check_meta(char c)
{
	if (c != '>' && c != '<' && c != '+' && c != '@'
		&& c != '|' && c != ' ' && c != '.' && c != '$')
		return (1);
	else
		return (0);
}

char	*update_dollar(t_data **data, char *line, int *start)
{
	int		i;
	char	front[256];
	char	back[256];
	char	*rt;

	i = 0;
	while (line[*start] && check_meta(line[*start]))
		front[i++] = line[(*start)++];
	front[i] = '\0';
	i = 0;
	while (line[*start])
		back[i++] = line[(*start)++];
	back[i] = '\0';
	rt = do_expansion(data, front, back);
	return (rt);
}

void	expansion( t_data **data, char **line)
{
	char	*temp;
	char	*env;
	int		i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '$')
		{
			temp = ft_substr(*line, 0, i);
			i++;
			env = update_dollar(data, *line, &i);
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

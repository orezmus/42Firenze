/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:28:00 by femorell          #+#    #+#             */
/*   Updated: 2024/01/26 00:40:06 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*extract_envp(char *line, t_data **data)
{
	int		i;
	char	*rt;
	char	*new;
	char	**temp;

	new = ft_strjoin(line, "=");
	i = -1;
	rt = NULL;
	while ((*data)->envp[++i])
	{
		if (ft_strncmp((*data)->envp[i], new, ft_strlen(new)) == 0)
		{
			temp = ft_split((*data)->envp[i], '=');
			rt = ft_strdup(temp[1]);
			free(new);
			free(temp);
			return (rt);
		}
	}
	free(new);
	return (rt);
}

static char	*do_expansion(char *line, char *back, t_data **data)
{
	char	*temp;
	char	*rt;

	if (extract_envp(line, data) != NULL)
		temp = extract_envp(line, data);
	else if (ft_atoi(line) > -1)
		temp = (*data)->argv[ft_atoi(line)];
	else if (line[0] == '#')
		temp = ft_itoa((*data)->argc);
	else if (line[0] == '?')
		temp = ft_itoa(g_exit_status);
	else
		temp = "";
	rt = ft_strjoin(temp, back);
	return (rt);
}

static char	*update_dollar(char *line, int *start, t_data **data)
{
	int		i;
	char	front[256];
	char	back[256];
	char	*rt;

	i = 0;
	while (line[*start] && ft_isalnum(line[*start]))
		front[i++] = line[(*start)++];
	front[i] = '\0';
	i = 0;
	while (line[*start])
		back[i++] = line[(*start)++];
	back[i] = '\0';
	rt = do_expansion(front, back, data);
	return (rt);
}

static void	update_expansion(char **line, t_data **data)
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
			env = update_dollar(*line, &i, data);
			//free(line);
			*line = ft_strjoin(temp, env);
			free(temp);
			free(env);
		}
		else
			i++;
	}
}

void	expansion(t_data **data)
{
	t_cmd	*cmd;
	t_list	*current;

	current = (*data)->command;
	while (current)
	{
		cmd = (t_cmd *)current->content;
		if (ft_strchr(cmd->line, '$') && cmd->type != SQUOTE)
		{
			update_expansion(&cmd->line, data);
			cmd->type = DOLLAR;
		}
		current = current->next;
	}
}

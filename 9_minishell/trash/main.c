/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:27 by sum               #+#    #+#             */
/*   Updated: 2023/11/21 15:24:29 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


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

static void	print_prompt(char **line)
{
	*line = readline("\033[34;1mbunnyfox$\033[0m ");
	if (*line == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
	else if (**line)
		add_history(*line);
	if (**line == '\0')
		free(*line);	
}


t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;
	
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->type = -1;
	cmd->line = NULL;
	return (cmd);
}

static int	check_quotes(char *line, char quote, int *i)
{
	int	temp;
	int	rt;
	
	temp = *i;
	while (line[temp])
	{
		if (line[temp] == quote)
			return (temp);
		temp++;
	}
	return (-1);
}

static void	add_list(t_data **data, char *line, int type)
{
	t_cmd	*cmd;
	
	cmd->type = type;
	cmd->line = line;
	if ((*data)->command == 0)
		(*data)->command = ft_lstnew(cmd);
	else
		ft_lstadd_back(&(*data)->command , ft_lstnew(cmd));

}

static void	extract_meta(int *i, char *line, t_data **data)
{
	t_cmd	*cmd;
	
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

static int	extract_quote(int *i, char *line, t_data **data)
{
	char	*new;
	int	temp;
	char	quote;
	t_cmd	*cmd;
	
	quote = line[(*i)++];
	temp = check_quotes(line , quote, i);
	if (temp == -1)
		return (-1);
	if (temp - *i > 0)
	{
		new = ft_substr(line, *i, temp - *i);
		if (quote == '\'')
			add_list(data, new, SQUOTE);
		else
			add_list(data, new, DQUOTE);
	}
	return (0);
}
	


static void	extract_arg(int *i, char *line, t_data **data)
{
	char	*new;
	int	temp;
	t_cmd	*cmd;
	
	temp = *i;
	while (line[*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != '|' 
	&& line[*i] != ' ' && line[*i] != '"' && line[*i] != '\'' && line[*i] != '\\'
	&& line[*i] != ';')
		(*i)++;
	if (*i - temp)
	{
		new = ft_substr(line, temp, *i - temp);
		add_list(data, new, ARG);
	}
	(*i)--;
}

static int	parsing(t_data **data, char *line)
{
	int	i;
	t_cmd	*cmd;
	
	cmd = init_cmd();
	i = -1;
	while(line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '"' || line[i] == '\'')
			extract_quote(&i, line, &(*data));
		else if (line[i] == '\\' || line [i] == ';')
			printf("error\n");
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			extract_meta(&i, line, &(*data));
		else
			extract_arg(&i, line, &(*data));
	}
	return (0);
}
		
		
int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data *data = malloc(sizeof(t_data));
	t_list	*command;
	t_cmd	*cmd;
	
	data->command = 0;
	set_signal();
	//alloc_envp(argc, argv, evnp);
	//print_logo();
	while(1)
	{
		print_prompt(&line);
		if (!parsing(&data, line))
			break;
		
	}
	/*/command = data->command;
	while (command)
	{
		cmd = ((t_cmd *)command->content);
		printf("%s \n", cmd->line);
		command = command->next;
	}*/

	return (0);
}

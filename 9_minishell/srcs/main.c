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
#include <dirent.h>

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
	if (!cmd)
		return NULL;
	cmd->type = -1;
	cmd->line = ft_strdup("");
	return (cmd);
}

static int	check_quotes(char *line, char quote, int *i)
{
	int	temp;
	
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
	
	cmd = init_cmd();
	cmd->type = type;
	cmd->line = line;
	if ((*data)->command == 0)
		(*data)->command = ft_lstnew(cmd);
	else
		ft_lstadd_back(&(*data)->command , ft_lstnew(cmd));

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

static int	extract_quote(int *i, char *line, t_data **data)
{
	char	*new;
	int	temp;
	char	quote;

	quote = line[(*i)++];
	printf("%c\n", quote);
	printf("%d\n",*i);
	temp = check_quotes(line , quote, i);
	if (temp == -1)
		printf("eroor\n");
	if (temp - *i > 0)
	{
		printf("tem[ %d i %d\n",temp, *i);
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

int	check_redir(t_list *command)
{
	t_cmd *cmd;
	 
	cmd = ((t_cmd *)command->content);
	if (!command->next)
	{
		ft_putstr_fd \
		("bunnyfox: syntax error near unexpected token `newline'\n", 2);
		return (1);
	}
	else if (cmd->type != REDIRIN && opendir(((t_cmd *)command->next->content)->line))
	{
		ft_putstr_fd("bunnyfox: ", 2);
		ft_putstr_fd(((t_cmd *)command->next->content)->line, 2);
		ft_putstr_fd(": Is a Directory\n", 2);
		return (1);
	}
	return (1);
}

void	free_list(t_data *data)
{
	t_list	*current;
	t_list	*next;
	//t_cmd	*cmd;

	current = data->command;
	//cmd = (t_cmd *)current->content;
	while (current != NULL)
	{
		next = current->next;
		if (current->content != NULL)
		{
			free(((t_cmd *)current->content)->line);
			free(current->content);
		}
		//free(current);
		current = next;
	}
	
}

int	check_syntax(t_data **data)
{
	t_cmd	*cmd;
	t_list	*lol;

	lol = (*data)->command;
	while (lol)
	{
		cmd = (t_cmd *)(*data)->command->content;
		if (cmd->type == PIPE)
		{
			ft_putstr_fd("bunnyfox: syntax error near unexpected token `|'\n", 2);
			
			//free_list(*data);
			return (1);
		}
		if (cmd->type != ARG && check_redir((*data)->command))
		{
			
			//free_list(*data);
			return (1);
		}
		//(*data)->command = (*data)->command->next;
		lol = lol->next;
  	  }

	return (1);
}
		
		
static int	parsing(t_data **data, char *line)
{
	int	i;
	
	i = -1;
	while(line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '"' || line[i] == '\'')
			extract_quote(&i, line, &(*data));
		else if (line[i] == '\\' || line [i] == ';')
			return (0);
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			extract_meta(&i, line, &(*data));
		else
			extract_arg(&i, line, &(*data));
	}
	
	return (check_syntax(data));
}
		
		
int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data *data = malloc(sizeof(t_data));
	t_list	*command;
	t_cmd	*cmd;
	
	data->command = 0;
	set_signal();
	(void)envp;
	(void)argc;
	(void)argv;
	//alloc_envp(argc, argv, evnp);
	//print_logo();
	while(1)
	{
		print_prompt(&line);
		if (!parsing(&data, line))
			break;
		
		command = data->command;
		//free_list(data);
		
		while (command)
		{
			cmd = ((t_cmd *)command->content);
			printf("prin %s \n", cmd->line);
			command = command->next;
		}
	}
	/*
	command = data->command;
	while (command)
		{
			cmd = ((t_cmd *)command->content);
			printf("%s \n", cmd->line);
			command = command->next;
		}
	*/	
	return (0);
}

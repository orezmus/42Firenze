/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:29 by sum               #+#    #+#             */
/*   Updated: 2024/01/26 10:55:30 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


# define STDIN 		0
# define STDOUT 		1
# define STDERR 		2


# define REDIROUT 		3
# define REDIRIN 		4
# define APPEND 		5
# define HEREDOC		6
# define PIPE 			7
# define DQUOTE 		8
# define SQUOTE		9
# define ARG			10

# define BUILTIN		51
# define CMD			52

# define DIR			88
# define FILE			89
# define DOLLAR		44


typedef struct s_cmd {
	int		type;
	char 		*line;
}	t_cmd;

typedef struct s_data {
	int			arg;
	int			fork;
	int			argc;
	int			fd[3][2];
	int			exit_status;
	int			flag;
	char			**argv;
	char			**envp;
	char			**cmdline;
	t_list			*command;

}	t_data;

extern int		g_exit_status;

void	set_signal(void);
t_cmd	*init_cmd(void);
int	envp_len(char **envp);
int	valid_key(char *key);

void	ft_cd(t_data *data, t_list *command);
void	ft_pwd(void);
void	ft_env(t_list *command, char **envp);
void	ft_echo(t_list *command);
void	ft_exit(t_data *data, t_list *command);
void	ft_unset(t_data *data, t_list *command);
void	ft_export(t_data *data, t_list *command);

int	parsing(t_data **data, char *line);
int	check_syntax(t_data **data);
int	check_redir(t_list *command);
int	update_arg(t_data **data);
void	expansion(t_data **data);
char	*extract_envp(char *line, t_data **data);
void	print_msg(int sign, char *str, char *msg);
int	ft_strcmp(const char *s1, const char *s2);
void	free_list(t_data *data);
void	add_list(t_data **data, char *line, int type);

void	exit_child(int pid);
void	heredoc_handle_signal(int signal);

void	exit_status(int *exit, int code);

#endif


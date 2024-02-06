/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:29 by sum               #+#    #+#             */
/*   Updated: 2024/02/03 13:38:35 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define REDIROUT 		3
# define REDIRIN 		4
# define APPEND 		5
# define HEREDOC		6
# define PIPE 			7
# define DQUOTE 		8
# define SQUOTE			9

# define BUILTIN		10
# define CMD			11
# define ARG			12

# define DIR			88
# define FILE			89
# define DOLLAR			44

typedef struct s_cmd
{
	int		type;
	char	*line;
}	t_cmd;

typedef struct s_data
{
	int			arg;
	int			fork;
	int			argc;
	int			fd[3][2];
	int			heredoc[2];
	int			exit_status;
	int			flag;
	char		**argv;
	char		**envp;
	char		**cmdline;
	t_list		*command;
}	t_data;

extern int	g_exit;

void	set_signal(void);
void	unlink_heredoc(t_data *data);

void	fd_backup(t_data *data, int *stdin, int *stdout);
void	print_prompt(char **input, t_data *data);
void	free_shell(t_data *data);
void	close_fd(void);
void	extract_meta(int *i, char *line, t_data **data);

// prompt_utils.c
void	escape_quote(char *next_line, char **input, char escape_type);
void	escape_backslash(char *next_line, char **input, char escape_type);
void	escape_pipe(char *next_line, char **input, char escape_type);

// parsing.c
int		parsing(t_data **data, char *line);

// envp.c
void	alloc_envp(t_data **data, int argc, char **argv, char **envp);
char	*extract_envp(t_data **data, char *line);
int		envp_len(char **envp);
int		find_key(t_data *data, char *key);

// builtin
void	ft_cd(t_data *data, t_list *command);
void	ft_pwd(void);
void	ft_env(t_list *command, char **envp);
void	ft_echo(t_list *command);
void	ft_exit(t_data *data, t_list *command);
void	ft_unset(t_data *data, t_list *command);
void	ft_export(t_data *data, t_list *command);

// cd_utils.c
void	update_pwd(t_data *data);
void	update_oldpwd(t_data *data, char *path);
char	**put_slash(t_data *data);
int		ft_cd_path(t_list *command, char **cd_path);
int		exist_home(char *path, char *home);
int		no_home(t_data *data, char *path);

// check.c
int		check_syntax(t_data **data);
int		check_redir(t_list *command);

// update.c
int		update_arg(t_data **data);

// expansion.c
void	expansion( t_data **data, char **line);
char	*do_expansion(t_data **data, char *line, char *back);

// execute.c
void	execute(t_data *data);
void	exec_list(t_data *data, t_list *command);
void	init_execute(t_data **data);
void	exec_builtin(t_data *data, t_list *command);

void	exec_file(t_data *data, t_list *command);
void	exec_cmd(t_data *data, t_list *command);

// heredoc.c
int		exec_heredoc(t_data *data, t_list *command);
void	heredoc_nl(char **str);
void	expansion_heredoc(t_data **data, char **line);

// redirect.c
void	redir_out(t_data *data, t_list *command, int append);
void	redir_in(t_data *data, t_list *command);
void	here_doc(t_data *data, t_list *command);

// builtin.c
void	exec_builtin(t_data *data, t_list *command);
void	exec_fork_builtin(t_data *data, t_list *command);

// ft_export.c
int		valid_key(char *key);

// list.c
t_cmd	*init_cmd(void);
void	free_list(t_data *data);
void	add_list(t_data **data, char *line, int type);

// utils.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(int c);
void	exit_status(int *exit, int code);
void	free_split(char **str);

// error.c
void	print_msg(int sign, char *msg);
void	print_error(char *cmd, char *str, char *msg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:29 by sum               #+#    #+#             */
/*   Updated: 2023/11/21 16:07:31 by sum              ###   ########.fr       */
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
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>

#include <readline/readline.h>
#include <readline/history.h>


# define STDIN 		0
# define STDOUT 		1
# define STDERR 		2

# define APPEND 3
# define HEREDOC 4
# define PIPE 5
# define DQUOTE 6
# define SQUOTE 7
# define ARG	8
# define REDIROUT 9
# define REDIRIN 10


typedef struct s_cmd {
	int		type;
	char 		*line;
}	t_cmd;

typedef struct s_data {

	t_list			*command;

}	t_data;

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:08:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/12 21:44:38 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "super_split.h"
# include <sys/wait.h>
# include <sys/errno.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>

# define SHELL_NAME "minishell"
# define PROMPT_STRING "minishell> "

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MINISHELL_EXIT 128

typedef struct	s_command {
	char	**argv;
	int		fd_in;
	int		fd_out;
}				t_command;

typedef struct	s_command_tab {
	t_command	*commands;
	size_t		number_of_commands;
}				t_command_tab;

typedef struct	s_env_variable {
	char	*name;
	char	*value;
}				t_env_variable;

t_command_tab	*read_command(void);
t_command_tab	*parse_command(char *command);
void			execute_command(t_command_tab *command_table);
void			free_command_table(t_command_tab *command_table);

void			delete_env_var(void *env_var);
void			clear_env(void);
char			*get_env_value(char *name);
t_env_variable	*create_env_var(char *name, char *value);
void			add_env_var(char *name, char *value);
char			*insert_env_variables(char *command);
void			print_error_and_exit(void);

extern t_list	*g_env;

#endif

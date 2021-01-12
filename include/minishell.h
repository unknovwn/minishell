/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:03:31 by mgeneviv          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/11 22:36:53 by mgeneviv         ###   ########.fr       */
=======
/*   Updated: 2021/01/11 17:15:41 by mgeneviv         ###   ########.fr       */
>>>>>>> 2589428f232e000ced860f338be93b0b79611f58
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

#endif

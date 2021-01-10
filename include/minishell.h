/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:03:31 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/10 17:19:36 by mgeneviv         ###   ########.fr       */
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

# define MINISHELL_EXIT 2

typedef struct	s_command {
	char	**argv;
	int		fd_in;
	int		fd_out;
}				t_command;

typedef struct	s_command_tab {
	t_command	*commands;
	size_t		number_of_commands;
}				t_command_tab;

t_command_tab	*read_command(void);
void			execute_command(t_command_tab *command_table);
void			free_command_table(t_command_tab *command_table);

#endif

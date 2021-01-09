/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:03:31 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/09 18:03:43 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <sys/errno.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>

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

t_command		**read_command(void);
char			*execute(t_command **command_table);
void			print(char *command_result);
void			free_command_table(t_command **command_table);

#endif

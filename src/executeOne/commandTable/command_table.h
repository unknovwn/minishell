/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:08:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 18:23:44 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_TABLE_H
# define COMMAND_TABLE_H

# include <stdlib.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_command {
	char		**argv;
	int			in;
	int			out;
}				t_command;

typedef struct	s_command_tab {
	t_command	*cells;
	size_t		len;
}				t_command_tab;

t_command_tab	*init_command_tab(void);
void			del_command_tab(t_command_tab **tab);

int				init_default(t_command_tab *tab, char **commands);
size_t			count_strs(char **commands);

int				set_redirect_between_commands(t_command_tab *tab);
int				commands_to_command_tab(t_command_tab *tab, char **commands);
int				set_argv(t_command *cells, char *command);
int				set_redirect_from(t_command *cell, char *command);

int				is_redirect_from(char *s);
int				is_redirect_to(char *s);
int				is_redirect_double_to(char *s);
int				is_redirect_or_space(char *s);

#endif

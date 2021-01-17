/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:08:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:11:26 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_TABLE_H
# define COMMAND_TABLE_H

# include <stdlib.h>
# include "split_str.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_command {
	char		**argv;
	int			in;
	int			out;
}				t_command;

/*
** ==========================================================================
**               Functions wich works with s_command only.
** ==========================================================================
*/

int				set_redirect_from(t_command *cell, t_split_str s);
int				set_redirect_to(t_command *cell, t_split_str s);
int				set_redirect_double_to(t_command *cell, t_split_str s);

/*
** ==========================================================================
** ==========================================================================
*/

typedef struct	s_command_tab {
	t_command	*cells;
	size_t		len;
}				t_command_tab;

/*
** ==========================================================================
**               Functions wich works with s_command_tab only.
** ==========================================================================
*/

t_command_tab	*init_command_tab(void);
void			del_command_tab(t_command_tab **tab);
int				init_default(t_command_tab *tab, char **commands);

int				set_redirect_between_commands(t_command_tab *tab);

int				commands_to_command_tab(t_command_tab *tab, char **commands);

t_command_tab	*parse_command(char *command);

/*
** ==========================================================================
** ==========================================================================
*/

/*
** ==========================================================================
**                             Utils.
** ==========================================================================
*/

size_t			count_strs(char **commands);
char			**split_argv(char *command);

int				is_redirect_from(char *s);
int				is_redirect_to(char *s);
int				is_redirect_double_to(char *s);
int				is_redirect_or_space(char *s);

/*
** ==========================================================================
** ==========================================================================
*/

#endif

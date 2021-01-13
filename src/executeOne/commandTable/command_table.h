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

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_command {
	char		**argv;
	int			in;
	int			out;
}				t_command;

typedef struct	s_command_tab {
	t_command	*commands;
	size_t		len;
}				t_command_tab;

t_command_tab	*init_default(char *commands);

#endif

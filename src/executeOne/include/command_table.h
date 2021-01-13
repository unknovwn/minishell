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

#ifndef MINISHELL_H
# define MINISHELL_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_command {
	char	**argv;
	int		in;
	int		out;
}				t_command;

typedef struct	s_command_tab {
	t_command	*commands;
	size_t		len;
}				t_command_tab;

typedef struct	s_env_variable {
	char	*name;
	char	*value;
}				t_env_variable;

#endif

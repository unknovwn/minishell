/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/16 17:24:07 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>
#include <signal.h>

t_list	*g_env;
int		g_exit_code;

void	repl(void)
{
	char	*command;
	int		return_value;
	char	*ascii_return_value;

	while (1)
	{
		if (!(command = read_command()))
			continue ;
		return_value = execute_command(command);
		if (return_value == MINISHELL_EXIT)
			break ;
		if (!(ascii_return_value = ft_uitoa(return_value)))
			continue ;
		set_new_value("?", ascii_return_value);
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_exit_code = 0;
	g_env = init_env();
	while (*envp)
		parse_env_var(*envp++);
	repl();
	clear_env();
	return (g_exit_code);
}

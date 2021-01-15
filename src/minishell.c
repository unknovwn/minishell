/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 22:21:30 by mgeneviv         ###   ########.fr       */
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

t_list		*g_env;
int			g_exit_code;

void		read_and_execute(void)
{
	char			*command;

	if (!(command = read_command()))
		print_error_and_exit(strerror(errno));
	execute_command(command);
	exit(0);
}

void		repl(void)
{
	int				pid;
	int				status;

	while (1)
	{
		if ((pid = fork()) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		if (pid == 0)
			read_and_execute();
		if ((waitpid(pid, &status, 0)) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		if (WEXITSTATUS(status) == MINISHELL_EXIT)
			break ;
	}
}

int			main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_exit_code = 0;
	if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGINT\n", SHELL_NAME);
	if ((signal(SIGQUIT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGQUIT\n", SHELL_NAME);
	g_env = init_env();
	while (*envp)
		parse_env_var(*envp++);
	repl();
	clear_env();
	return (g_exit_code);
}

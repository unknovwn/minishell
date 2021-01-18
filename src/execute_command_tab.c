/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:37:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 21:17:50 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "command_table.h"
#include "libft.h"
#include "execute_command_tab_utils.h"
#include "print_error.h"
#include "find_path.h"
#include "create_envp.h"

#include <sys/errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

void		find_and_execute(char **argv)
{
	struct stat	sb;
	char		*path;
	char		**envp;

	if (!(ft_strchr(argv[0], '/')))
	{
		if (!(path = find_path(argv[0])))
			print_error_and_exit(127, argv[0], "command not found");
	}
	else
		path = argv[0];
	if ((stat(path, &sb)) == -1)
		print_error_and_exit(1, path, strerror(errno));
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		print_error_and_exit(126, path, "is a directory");
	if (!(envp = create_envp()))
		print_error_and_exit(1, 0, strerror(errno));
	if ((execve(path, argv, envp)) == -1)
		print_error_and_exit(126, path, strerror(errno));
}

int			execute_command(t_command_tab *tab, size_t i)
{
	int	ret;
	int	pid;

	if ((ret = execute_builtin(tab->cells[i].argv)) != -1)
		return (ret);
	if ((pid = fork()) == -1)
	{
		print_error(0, strerror(errno));
		return (1);
	}
	if (pid == 0)
	{
		if ((signal(SIGINT, SIG_DFL)) == SIG_ERR)
			print_error(0, "Error: Cannot catch SIGINT");
		if ((signal(SIGQUIT, SIG_DFL)) == SIG_ERR)
			print_error(0, "Error: Cannot catch SIGQUIT");
		if (is_in_redirected(tab->cells[i].in) && i > 0
				&& is_out_redirected(tab->cells[i - 1].out))
			close((tab->cells[i - 1]).out);
		if (is_out_redirected(tab->cells[i].out) && i + 1 < tab->len
				&& is_in_redirected(tab->cells[i + 1].in))
			close((tab->cells[i + 1]).in);
		find_and_execute((tab->cells[i]).argv);
	}
	return (ret);
}

void		redirect_streams(int in, int out)
{
	if (is_in_redirected(in))
	{
		if ((dup2(in, STDIN)) == -1)
			print_error(0, strerror(errno));
	}
	if (is_out_redirected(out))
	{
		if ((dup2(out, STDOUT)) == -1)
			print_error(0, strerror(errno));
	}
}

int			redirect_execute(t_command_tab *tab, size_t i)
{
	int ret;

	redirect_streams(tab->cells[i].in, tab->cells[i].out);
	ret = execute_command(tab, i);
	if (is_in_redirected(tab->cells[i].in))
	{
		close((tab->cells[i]).in);
		if ((dup2(g_sin, STDIN)) == -1)
		{
			print_error(0, strerror(errno));
			return (MINISHELL_EXIT);
		}
	}
	if (is_out_redirected(tab->cells[i].out))
	{
		close((tab->cells[i]).out);
		if ((dup2(g_sout, STDOUT)) == -1)
		{
			print_error(0, strerror(errno));
			return (MINISHELL_EXIT);
		}
	}
	return (ret);
}

int			execute_command_tab(t_command_tab *tab)
{
	size_t	i;
	int		status;
	int		ret;

	if (tab->len == 0)
		return (0);
	i = 0;
	while (i < tab->len)
	{
		if ((tab->cells[i]).argv)
			ret = redirect_execute(tab, i);
		i++;
	}
	while (0 < wait(&status))
		;
	if (ret == -1)
		ret = WEXITSTATUS(status);
	return (ret);
}

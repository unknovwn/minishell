/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:37:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:34:20 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "command_table.h"
#include "libft.h"
#include "builtins.h"
#include "print_error.h"
#include "find_path.h"
#include "create_envp.h"

#include <sys/errno.h>
#include <string.h>
#include <sys/wait.h>

int		is_in_redirected(t_command command)
{
	return (command.in != STDIN);
}

int		is_out_redirected(t_command command)
{
	return (command.out != STDOUT);
}

int		count_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (*argv++)
		argc++;
	return (argc);
}

int		execute_builtin(char **argv)
{
	int argc;

	argc = count_argc(argv);
	if ((ft_strcmp(argv[0], "echo")) == 0)
		return(echo_command(argc, argv));
	if ((ft_strcmp(argv[0], "cd")) == 0)
		return(cd_command(argc, argv));
	if ((ft_strcmp(argv[0], "pwd")) == 0)
		return(pwd_command());
	if ((ft_strcmp(argv[0], "export")) == 0)
		return(export_command(argc, argv));
	if ((ft_strcmp(argv[0], "unset")) == 0)
		return(unset_command(argc, argv));
	if ((ft_strcmp(argv[0], "env")) == 0)
		return(env_command());
	if ((ft_strcmp(argv[0], "exit")) == 0)
		return(exit_command(argc, argv));
	return (-1);
}

void	find_and_execute(char **argv)
{
	char	*path;
	char	**envp;

	if (!(ft_strchr(argv[0], '/')))
	{
		if (!(path = find_path(argv[0])))
			print_error_and_exit(127, argv[0], "command not found");
	}
	else
		path = argv[0];
	if (!(envp = create_envp()))
		print_error_and_exit(1, 0, strerror(errno));
	if ((execve(path, argv, envp)) == -1)
		print_error_and_exit(126, path, strerror(errno));
}

int		execute_pipe(t_command_tab *tab)
{
	size_t	i;
	int		pid;
	int		status;
	int		ret;

	if (tab->len == 0)
		return (0);
	i = 0;
	while (i < tab->len)
	{
		if (!((tab->cells[i]).argv))
		{
			i++;
			continue ;
		}
		if (i > 0 && is_out_redirected(tab->cells[i - 1]))
			close(tab->cells[i - 1].out);
		if (i + 1 < tab->len && is_in_redirected(tab->cells[i + 1]))
			close(tab->cells[i + 1].in);
		if (is_in_redirected(tab->cells[i]))
		{
			if ((dup2((tab->cells[i]).in, STDIN)) == -1)
				print_error(0, strerror(errno));
		}
		if (is_out_redirected(tab->cells[i]))
		{
			if ((dup2((tab->cells[i]).out, STDOUT)) == -1)
				print_error(0, strerror(errno));
		}
		if ((ret = execute_builtin((tab->cells[i]).argv)) == -1)
		{
			if ((pid = fork()) == -1)
			{
				print_error(0, strerror(errno));
				break ;
			}
			if (pid == 0)
				find_and_execute((tab->cells[i]).argv);
		}
		if (i > 0 && is_out_redirected(tab->cells[i - 1]))
			close(tab->cells[i - 1].out);
		if (is_in_redirected(tab->cells[i]))
			close(tab->cells[i].in);
		if (i + 1 < tab->len && is_in_redirected(tab->cells[i + 1]))
			close(tab->cells[i + 1].in);
		if (is_out_redirected(tab->cells[i]))
			close(tab->cells[i].out);
		i++;
	}
	while (0 < wait(&status));
	if (ret == -1)
		ret = WEXITSTATUS(status);
	return (ret);
}

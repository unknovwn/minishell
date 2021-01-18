/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_tab_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:26:52 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 15:35:29 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "libft.h"
#include "builtins.h"

int	is_in_redirected(int fd)
{
	return (fd != STDIN);
}

int	is_out_redirected(int fd)
{
	return (fd != STDOUT);
}

int	count_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (*argv++)
		argc++;
	return (argc);
}

int	execute_builtin(char **argv)
{
	int argc;

	argc = count_argc(argv);
	if ((ft_strcmp(argv[0], "echo")) == 0)
		return (echo_command(argc, argv));
	if ((ft_strcmp(argv[0], "cd")) == 0)
		return (cd_command(argc, argv));
	if ((ft_strcmp(argv[0], "pwd")) == 0)
		return (pwd_command());
	if ((ft_strcmp(argv[0], "export")) == 0)
		return (export_command(argc, argv));
	if ((ft_strcmp(argv[0], "unset")) == 0)
		return (unset_command(argc, argv));
	if ((ft_strcmp(argv[0], "env")) == 0)
		return (env_command());
	if ((ft_strcmp(argv[0], "exit")) == 0)
		return (exit_command(argc, argv));
	return (-1);
}

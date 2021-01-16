/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:16:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/16 21:07:35 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "super_split.h"
#include "print_error.h"
#include "libft.h"
#include "env_utils.h"
#include <sys/errno.h>
#include <string.h>

int		iss_semicolon(char *c)
{
	return (*c == ';');
}

int		execute_command(char *command)
{
	char	**commands;
	int		i;

	if (ft_strlen(command) == 0 || ft_strcmp(command, "exit\n") == 0)
	{
		clear_env();
		free(command);
		ft_putstr("exit\n", STDOUT);
		return (MINISHELL_EXIT);
	}
	command[ft_strlen(command) - 1] = '\0';
	if (!(commands = super_split(command, iss_semicolon)))
	{
		free(command);
		print_error(0, strerror(errno));
		return (1);
	}
	ft_putstr("\"", STDOUT);
	i = 0;
	while (commands[i])
	{
		/* if ((execute_one(*commands)) == -1) */
		/* { */
		/* 	if (errno) */
		/* 		ft_fprintf(STDOUT, "%s: %s\n", SHELL_NAME, strerror(errno)) */
		/* } */
		ft_fprintf(STDOUT, "%s", commands[i]);
		if (commands[++i])
			ft_putstr(";", STDOUT);
	}
	ft_putstr("\"\n", STDOUT);
	free_string_arr(commands);
	free(command);
	return (0);
}

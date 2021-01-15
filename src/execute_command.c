/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:16:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 13:58:48 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "super_split.h"
#include "print_error.h"
#include "libft.h"
#include <sys/errno.h>
#include <string.h>

int		iss_semicolon(char *c)
{
	return (*c == ';');
}

void	execute_command(char *command)
{
	char	**commands;
	int		i;

	if (ft_strlen(command) == 0 || ft_strcmp(command, "exit\n") == 0)
	{
		free(command);
		ft_putstr("exit\n", STDOUT);
		exit(MINISHELL_EXIT);
	}
	command[ft_strlen(command) - 1] = '\0';
	if (!(commands = super_split(command, iss_semicolon)))
	{
		free(command);
		print_error_and_exit(strerror(errno));
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
}

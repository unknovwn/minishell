/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:16:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 19:05:55 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char *command)
{
	/* char	**commands; */

	if (ft_strlen(command) == 0 || ft_strcmp(command, "exit\n") == 0)
	{
		/* free_command_table(command_table); */
		free(command);
		ft_putstr("exit\n", STDOUT);
		exit(MINISHELL_EXIT);
	}
	command[ft_strlen(command) - 1] = '\0';
	ft_fprintf(STDOUT, "\"%s\" executed\n", command);
	/* if (!(commands = super_split(command, is_semicolon))) */
	/* { */
	/* 	free(command); */
	/* 	print_error_and_exit(strerror(errno)); */
	/* } */
	/* while (*commands) */
	/* { */
	/* 	if ((execute_one(*commands)) == -1) */
	/* 	{ */
	/* 		if (errno) */
	/* 			ft_fprintf(STDOUT, "%s: %s\n", SHELL_NAME, strerror(errno)) */
	/* 	} */
	/* 	commands++; */
	/* } */
	/* free_string_arr(commands); */
	free(command);
}

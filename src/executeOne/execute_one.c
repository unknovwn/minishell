/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*   Created: 2021/01/12 19:49:32 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/12 19:49:34 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "commandTable/command_table.h"
#include "super_split.h"
#include "libft.h"

static void	print_command_tab(t_command_tab *command_tab)
{
	t_command	*commands;
	size_t		i;

	commands = command_tab->commands;
	i = 0;
	while (i < command_tab->len)
	{
		printf("command #%zu:\n", i);
		if (commands->argv == NULL)
			printf("argv: NULL\n");
		printf("in = |%d|\n", commands[i].in);
		printf("out = |%d|\n", commands[i].out);
		printf("=============\n");
		i += 1;
	}
}

static void		free_all(t_command_tab *command_tab, char **strs)
{
	free_string_arr(strs);
	free_command_tab(&command_tab);
}

int				is_s_pipe(char *s)
{
	return (*s == '|');
}

int	execute_one(char *command)
{
	t_command_tab	*command_tab;
	char			**commands_by_pipe;

	commands_by_pipe = super_split(command, is_s_pipe);
	if (commands_by_pipe == NULL)
		return (-1);
	if ((command_tab = init_default(commands_by_pipe)) == NULL)
	{
		free_string_arr(commands_by_pipe);
		return (-1);
	}
	if (set_redirect_command_to_command(command_tab) != 0)
	{
		free_all(command_tab, commands_by_pipe);
		return (-1);
	}
	/*
	if (commands_to_command_tab(command_tab) != 0)
	{
		free_all(command_tab, commands_by_pipe);
		return (-1);
	}
	*/

	print_command_tab(command_tab);

	/* execute_commands(command_tab); */

	free_all(command_tab, commands_by_pipe);
	return (0);
}

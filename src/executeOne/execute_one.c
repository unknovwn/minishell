/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:49:32 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/12 19:49:34 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "commandTable/command_table.h"
#include "include/utils.h"
#include "include/super_split.h"
#include "include/libft.h"

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
		printf("in = |%d|\n", commands->in);
		printf("out = |%d|\n", commands->out);
		printf("=============\n");
		i += 1;
	}
}

void	execute_one(char *commands_by_semicolon)
{
	t_command_tab	*command_tab;

	command_tab = init_default(commands_by_semicolon);
	print_command_tab(command_tab);
	free(command_tab->commands);
	free(command_tab);
	sleep(30);
	return ;
}

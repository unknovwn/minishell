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
#include <unistd.h>

#include "commandTable/command_table.h"

static void	print_command_tab(t_command_tab *command_tab)
{
	t_command	*cells;
	size_t		i;

	cells = command_tab->cells;
	i = 0;
	while (i < command_tab->len)
	{
		printf("command #%zu:\n", i);
		if (cells[i].argv == NULL)
			printf("argv: NULL\n");
		else
		{
			for(int j = 0; cells[i].argv[j] != NULL; j += 1)
			{
				printf("argv[%d]: |%s|\n", j, cells[i].argv[j]);
			}
		}
		printf("in = |%d|\n", cells[i].in);
		printf("out = |%d|\n", cells[i].out);
		printf("=============\n");
		i += 1;
	}
}

int	execute_one(char *command)
{
	t_command_tab	*tab;
	char			**by_pipe;

	if ((tab = parse_command(command)) == NULL)
	{
		write(1, "execute_one error\n", 18);
		return (-1);
	}
	print_command_tab(tab);
	del_command_tab(&tab);
	sleep(30);
	return (0);
}

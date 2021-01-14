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

static void		free_all(t_command_tab *tab, char **strs)
{
	free_string_arr(strs);
	del_command_tab(&tab);
}

int				is_s_pipe(char *s)
{
	return (*s == '|');
}

int	execute_one(char *command)
{
	t_command_tab	*tab;
	char			**by_pipe;

	if ((tab = init_command_tab()) == NULL)
			return (-1);
	if ((by_pipe = super_split(command, is_s_pipe)) == NULL)
	{
		del_command_tab(&tab);
		return (-1);
	}
	if (init_default(tab, by_pipe) != 0)
	{
		free_all(tab, by_pipe);
		return (-1);
	}
	if (set_redirect_between_commands(tab) != 0)
	{
		free_all(tab, by_pipe);
		return (-1);
	}
	if (commands_to_command_tab(tab, by_pipe) != 0)
	{
		free_all(tab, by_pipe);
		return (-1);
	}
	print_command_tab(tab);
	free_all(tab, by_pipe);
	//sleep(30);
	return (0);
}

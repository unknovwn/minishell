/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:49:51 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/13 18:49:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/errno.h>

#include "command_table.h"
#include "super_split.h"
#include "utils.h"
#include "libft.h"

static size_t	count_commands(char **commands)
{
	size_t	len;

	len = 0;
	while (*commands != NULL)
	{
		len += 1;
		commands += 1;
	}
	return (len);
}

static void		set_defult(t_command_tab *command_tab)
{
	t_command	*commands;
	size_t		i;

	commands = command_tab->commands;
	i = 0;
	while (i < command_tab->len)
	{
		command_tab->commands[i].argv = NULL;
		command_tab->commands[i].in = STDIN;
		command_tab->commands[i].out = STDOUT;
		i += 1;
	}
}

t_command_tab	*init_default(char *commands)
{
	char			**commands_by_pipe;
	t_command_tab	*command_tab;

	commands_by_pipe = super_split(commands, is_pipe);
	if (commands_by_pipe == NULL)
		return (NULL);
	command_tab = (t_command_tab*)malloc(sizeof(t_command_tab));
	if (commands == NULL)
	{
		free_string_arr(commands_by_pipe);
		return (NULL);
	}
	command_tab->len = count_commands(commands_by_pipe);
	command_tab->commands = (t_command*)malloc(sizeof(t_command) * command_tab->len);
	if (command_tab->commands == NULL)
	{
		free_string_arr(commands_by_pipe);
		free(command_tab);
		return (NULL);
	}
	free_string_arr(commands_by_pipe);
	set_defult(command_tab);
	return (command_tab);
}

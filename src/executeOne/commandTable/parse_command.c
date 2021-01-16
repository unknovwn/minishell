/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:49:09 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 19:49:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "command_table.h"
#include "../super_split.h"
#include "../libft.h"
#include "../utils.h"

static int		set_command_tab(t_command_tab *tab, char *command)
{
	char			**by_pipe;

	if ((by_pipe = super_split(command, is_pipe)) == NULL)
		return (-1);
	if (init_default(tab, by_pipe) != 0)
	{
		free_string_arr(by_pipe);
		return (-1);
	}
	if (set_redirect_between_commands(tab) != 0)
	{
		free_string_arr(by_pipe);
		return (-1);
	}
	if (commands_to_command_tab(tab, by_pipe) != 0)
	{
		free_string_arr(by_pipe);
		return (-1);
	}
	free_string_arr(by_pipe);
	return (0);
}

t_command_tab	*parse_command(char *command)
{
	t_command_tab	*tab;

	if ((tab = init_command_tab()) == NULL)
		return (NULL);
	if (set_command_tab(tab, command) != 0)
	{
		del_command_tab(&tab);
		return (NULL);
	}
	return (tab);
}
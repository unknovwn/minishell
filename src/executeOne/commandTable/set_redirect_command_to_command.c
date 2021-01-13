/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_command_to_command.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:03:35 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/13 22:03:36 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "command_table.h"

int	set_redirect_command_to_command(t_command_tab *command_tab)
{
	t_command	*commands;
	int			new_in_out[2];
	size_t		i;

	commands = command_tab->commands;
	i = 0;
	while (i < command_tab->len - 1)
	{
		if (pipe(new_in_out) < 0)
			return (-1);
		commands[i].out = new_in_out[1];
		commands[i + 1].in = new_in_out[0];
		i += 1;
	}
	return (0);
}

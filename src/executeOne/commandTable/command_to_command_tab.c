/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_command_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:17:45 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 13:17:47 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "command_table.h"
#include "../super_split.h"
#include "../libft.h"
#include "../skipping.h"
#include "../files/files.h"

int	set_argv(t_command *cell, char *command)
{
	cell->argv = super_split(command, ft_s_isspace);
	if (cell->argv == NULL)
		return (-1);
	else
		return (0);
}

int	commands_to_command_tab(t_command_tab *tab, char **commands)
{
	t_command	*cells;
	size_t		i;

	cells = tab->cells;
	i = 0;
	while (i < tab->len)
	{
		if (set_redirect_from(&(cells[i]), commands[i]) != 0)
			return (-1);
		i += 1;
	}
	return (0);
}

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

#include <stdlib.h>

#include "command_table.h"

size_t			count_strs(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs != NULL)
	{
		len += 1;
		strs += 1;
	}
	return (len);
}

static void		set_defult(t_command_tab *command_tab)
{
	t_command	*cells;
	size_t		i;

	cells = command_tab->cells;
	i = 0;
	while (i < command_tab->len)
	{
		command_tab->cells[i].argv = NULL;
		command_tab->cells[i].in = STDIN;
		command_tab->cells[i].out = STDOUT;
		i += 1;
	}
}

int				init_default(t_command_tab *tab, char **commands)
{
	tab->len = count_strs(commands);
	tab->cells = (t_command*)malloc(sizeof(t_command) * tab->len);
	if (tab->cells == NULL)
		return (-1);
	set_defult(tab);
	return (0);
}

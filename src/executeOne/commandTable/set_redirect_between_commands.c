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

int	set_redirect_between_commands(t_command_tab *tab)
{
	t_command	*cells;
	int			new_in_out[2];
	size_t		i;

	cells = tab->cells;
	i = 0;
	while (i < tab->len - 1)
	{
		if (pipe(new_in_out) < 0)
			return (-1);
		cells[i].out = new_in_out[1];
		cells[i + 1].in = new_in_out[0];
		i += 1;
	}
	return (0);
}

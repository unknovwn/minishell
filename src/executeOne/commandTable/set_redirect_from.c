/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_from.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:07:52 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 21:07:53 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "command_table.h"
#include "../split_str.h"

int				set_redirect_from(t_command *cell, t_split_str s)
{
	char	*file;

	if ((file = copy_and_skip_string(&s)) == NULL)
		return (-1);
	if (cell->in != 0)
	{
		if (close(cell->in) < 0)
		{
			free(file);
			return (-1);
		}
	}
	if ((cell->in = open(file, O_RDONLY)) < 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

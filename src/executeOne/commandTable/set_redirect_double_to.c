/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect_double_to.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:16:02 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 20:26:46 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "command_table.h"
#include "split_str.h"

int			set_redirect_double_to(t_command *cell, t_split_str s)
{
	char	*file;

	if ((file = copy_and_skip_string(&s)) == NULL)
		return (-1);
	if (cell->out != STDOUT)
	{
		if (close(cell->out) < 0)
		{
			free(file);
			return (-1);
		}
	}
	if ((cell->out = open(file, O_CREAT | O_WRONLY | O_APPEND,
								S_IREAD | S_IWRITE)) < 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

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

#include <stdio.h>
#include <stdbool.h>

#include "command_table.h"
#include "../super_split.h"
#include "../split_str.h"
#include "../libft.h"
#include "../skipping.h"
#include "../files/files.h"

int		set_from(t_command *cell, char **by_from)
{
	char	**file_names;

	if ((file_names = take_file_names(by_from + 1)) == NULL)
		return (-1);
	free_string_arr(file_names);
	return (0);
}

int		set_redirect_from(t_command *cell, char *command)
{
	char	**by_from;
	size_t	len;

	if ((by_from = (char**)super_split(command, is_redirect_from)) == NULL)
		return (-1);
	if ((len = count_strs(by_from)) == 1)
	{
		free_string_arr(by_from);
		return (0);
	}
	else if (set_from(cell, by_from) != 0)
	{
		free_string_arr(by_from);
		return (-1);
	}
	free_string_arr(by_from);
	return (0);
}

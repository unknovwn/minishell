/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:47:08 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/12/29 21:19:43 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command_table(t_command **command_table)
{
	t_command **command_table_start;

	command_table_start = command_table;
	while (*command_table)
	{
		free_string_arr((*command_table)->argv);
		command_table++;
	}
	free((command_table_start));
}

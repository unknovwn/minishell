/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:47:08 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 18:25:20 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command_table(t_command_tab *command_table)
{
	int			i;
	t_command	*commands;

	commands = command_table->commands;
	i = command_table->len;
	while (i--)
	{
		free_string_arr(commands->argv);
		commands++;
	}
	free(command_table->commands);
	free(command_table);
}

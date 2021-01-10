/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:16:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/10 18:20:09 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	execute_command(t_command_tab *command_table)
{
	t_command	*commands;

	commands = command_table->commands;
	if ((strcmp(((commands[0]).argv)[0], "exit")) == 0)
	{
		ft_putstr("exit\n", STDOUT);
		free_command_table(command_table);
		exit(MINISHELL_EXIT);
	}
	if (((commands[0]).argv)[0])
		ft_fprintf(STDOUT, "\"%s\" executed\n", ((commands[0]).argv)[0]);
}

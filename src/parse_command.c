/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:56:39 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/12 20:18:16 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_tab	*parse_command(char *command)
{
	t_command_tab	*command_table;
	t_command		*commands;
	/* char			*error; */

	if ((error = check_syntax_errors(command)))
	{
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, error);
		return (0);
	}
	if (!(command = insert_env_variables(command)))
		return (0);
	if (!(command_table = (t_command_tab*)malloc(sizeof(t_command_tab))))
		return (0);
	command_table->number_of_commands = 1;
	if (!(command_table->commands = (t_command*)malloc(sizeof(t_command)
					* command_table->number_of_commands)))
	{
		free(command_table);
		return (0);
	}
	commands = command_table->commands;
	if (ft_strlen(command) == 0)
		(commands[0]).argv = super_split("exit", ft_isspace);
	else
		(commands[0]).argv = super_split(command, ft_isspace);
	return (command_table);
}


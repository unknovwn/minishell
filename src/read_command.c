/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/10 17:31:43 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_SIZE 1024

/* Remove "^C" from terminal */
static void		handle_inter(int sig)
{
	if (sig == SIGINT)
		ft_putstr("\b\b  \b\b", STDOUT);
	exit(0);
}

t_command_tab	*parse_command(char *command)
{
	t_command_tab	*command_table;
	t_command		*commands;

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
	{
		ft_putstr("exit\n", STDOUT);
		(commands[0]).argv = super_split("exit", ft_isspace);
	}
	else
		(commands[0]).argv = super_split(command, ft_isspace);
	return (command_table);
}

t_command_tab	*read_command(void)
{
	int		count;
	char	command[BUFFER_SIZE];
	char	buf[BUFFER_SIZE];
	int		ctrld_flag;
	size_t	command_len;

	signal(SIGINT, handle_inter);
	command_len = 0;
	ctrld_flag = 1;
	ft_putstr(PROMPT_STRING, STDOUT);
	while (ctrld_flag)
	{
		if ((count = read(0, buf, BUFFER_SIZE - 1)) == -1)
			return (0);
		buf[count] = '\0';
		ctrld_flag = (buf[count - 1] != '\n');
		command_len += count;
		ft_strlcpy(&command[command_len - count], buf, BUFFER_SIZE - command_len);
		if (ctrld_flag)
		{
			ft_putstr("  \b\b", STDOUT);
			if (command_len == 0)
				break ;
		}
	}
	return (parse_command(command));
}

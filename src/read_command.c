/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/09 21:08:20 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_SIZE 1024

/* Remove "^C" from terminal */
static void		handle_inter(int sig)
{
	if (sig == 2)
		ft_putstr("\b\b  \b\b", STDOUT);
	exit(0);
}

t_command		**parse_command(char *command)
{
	t_command	**command_table;

	command_table = (t_command**)malloc(sizeof(t_command*) * 2);
	command_table[0] = (t_command*)malloc(sizeof(t_command));
	if (ft_strlen(command) == 0)
		(command_table[0])->argv = super_split("exit", ft_isspace);
	else
		(*command_table)->argv = super_split(command, ft_isspace);
	command_table[1] = 0;
	return (command_table);
}

t_command		**read_command(void)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/11 19:21:12 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_SIZE 1024

/* Backspace special characters from terminal */
void			handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\b\b  \b\b\n", STDOUT);
		exit(0);
	}
	if (sig == SIGQUIT)
		ft_putstr("\b\b  \b\b", STDOUT);
}

int				has_not_closed_pipe(char *command)
{
	char	*command_without_spaces;
	char	*command_end;

	if (!(command_without_spaces = ft_remove_chars(command, ft_isspace)))
	{
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		exit(1);
	}
	command_end = command_without_spaces
		+ (ft_strlen(command_without_spaces) - 1);
	ft_fprintf(STDOUT, "\"%s\"\n", command_without_spaces);
	return (*command_end == '|' && command_end > command_without_spaces
			&& *(command_end - 1) != '|' && *(command_end - 1) != ';');
}

t_command_tab	*read_command(void)
{
	int		count;
	char	command[BUFFER_SIZE];
	char	buf[BUFFER_SIZE];
	int		ctrld_flag;
	size_t	command_len;
	int		remaining_command_space;

	if ((signal(SIGINT, handle_signal)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGINT\n", STDERR);
	if ((signal(SIGQUIT, handle_signal)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGQUIT\n", STDERR);
	command_len = 0;
	ctrld_flag = 1;
	ft_putstr(PROMPT_STRING, STDOUT);
	while (ctrld_flag)
	{
		if ((count = read(0, buf, BUFFER_SIZE - 1)) == -1)
			return (0);
		buf[count] = '\0';
		ctrld_flag = (count == 0 || buf[count - 1] != '\n');
		if ((remaining_command_space = BUFFER_SIZE - (command_len + count)) < 0)
			remaining_command_space = 0;
		ft_strlcpy(&command[command_len], buf, remaining_command_space);
		command_len += count;
		if (ctrld_flag)
		{
			ft_putstr("  \b\b", STDOUT);
			if (command_len == 0)
				break ;
		}
		else if (has_not_closed_pipe(command))
		{
			ft_putstr("pipe> ", STDOUT);
			ctrld_flag = 1;
		}
	}
	return (parse_command(command));
}

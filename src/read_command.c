/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 16:47:50 by mgeneviv         ###   ########.fr       */
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

int				has_not_closed_pipe(char *command, size_t command_len)
{
	char	*command_end;
	size_t	backslash_counter;

	if (command_len < 2)
		return (0);
	command_end = &(command[command_len - 1]);
	while (command_end >= command && ft_isspace(*command_end))
		command_end--;
	if (*command_end != '|')
		return (0);
	command_end--;
	backslash_counter = 0;
	while (command_end >= command && *command_end == '\\')
	{
		backslash_counter++;
		command_end--;
	}
	return (backslash_counter % 2 == 0);
}

int				ends_with_backslash_newline(char *command, size_t command_len)
{
	char	*command_end;
	size_t	backslash_counter;

	if (command_len < 2)
		return (0);
	command_end = &(command[command_len - 1]);
	if (*command_end != '\n')
		return (0);
	command_end--;
	backslash_counter = 0;
	while (command_end >= command && *command_end == '\\')
	{
		backslash_counter++;
		command_end--;
	}
	return (backslash_counter % 2 != 0);
}

t_command_tab	*read_command(void)
{
	int		count;
	char	command[BUFFER_SIZE];
	char	buf[BUFFER_SIZE];
	int		ctrld_flag;
	size_t	command_len;
	int		remaining_command_space;
	char	*syntax_error;

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
			continue ;
		}
		if ((syntax_error = check_syntax_errors(command)))
		{
			ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, syntax_error);
			exit(0);
		}
		if ((has_not_closed_pipe(command, command_len)))
		{
			ft_putstr("> ", STDOUT);
			ctrld_flag = 1;
		}
		if ((ends_with_backslash_newline(command, command_len)))
		{
			command[command_len - 2] = '\0';
			command_len -= 2;
			ft_putstr("> ", STDOUT);
			ctrld_flag = 1;
		}
	}
	return (parse_command(command));
}

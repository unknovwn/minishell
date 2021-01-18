/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 21:31:57 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"
#include "check_syntax_errors.h"
#include "read_utils.h"
#include "print_error.h"
#include <signal.h>
#include <sys/errno.h>
#include <string.h>

#define BUFFER_SIZE 262144

size_t	g_command_len;

void	handle_signal_read(int sig)
{
	if (sig == SIGINT)
	{
		ft_fprintf(STDOUT, "\b\b  \b\b\n%s", PROMPT_STRING);
		g_command_len = 0;
	}
	if (sig == SIGQUIT)
		ft_putstr("\b\b  \b\b", STDOUT);
}

int		check_sytnax(char *command, size_t *command_len, int count)
{
	char	*syntax_error;
	int		do_read;

	if ((do_read = (count == 0 || command[*command_len - 1] != '\n')))
	{
		ft_putstr("  \b\b", STDOUT);
		return (*command_len != 0);
	}
	if ((syntax_error = check_syntax_errors(command)))
	{
		set_new_value("?", "258", 1);
		print_error(0, syntax_error);
		return (-1);
	}
	if (has_unexpected_end(command, *command_len))
		return (1);
	if ((ends_with_backslash_newline(command, command_len)))
		return (1);
	return (do_read);
}

int		read_to_buf(char *buf)
{
	int		count;

	if ((count = read(STDIN, buf, BUFFER_SIZE - 1)) == -1)
	{
		print_error(0, strerror(errno));
		return (-1);
	}
	buf[count] = '\0';
	g_command_len += count;
	if (g_command_len >= BUFFER_SIZE)
		return (-1);
	return (count);
}

char	*read_command(void)
{
	char	buf[BUFFER_SIZE];
	char	command[BUFFER_SIZE];
	int		do_read;
	int		count;

	if ((signal(SIGINT, handle_signal_read)) == SIG_ERR)
		print_error(0, "Error: Cannot catch SIGINT");
	if ((signal(SIGQUIT, handle_signal_read)) == SIG_ERR)
		print_error(0, "Error: Cannot catch SIGQUIT");
	g_command_len = 0;
	do_read = 1;
	ft_putstr(PROMPT_STRING, STDOUT);
	while (do_read)
	{
		if ((count = read_to_buf(buf)) == -1)
			return (0);
		ft_strlcpy(&command[g_command_len - count],
				buf, BUFFER_SIZE - g_command_len);
		if ((do_read = check_sytnax(command, &g_command_len, count)) == -1)
			return (0);
	}
	return (insert_env_variables(command));
}

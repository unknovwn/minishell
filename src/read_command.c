/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 17:54:17 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"
#include "check_syntax_errors.h"
#include "print_error.h"
#include <signal.h>
#include <sys/errno.h>
#include <string.h>
#include <fcntl.h>
#include "skipping.h"

#define BUFFER_SIZE 262144

size_t	g_command_len;

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_fprintf(STDOUT, "\b\b  \b\b\n%s", PROMPT_STRING);
		g_command_len = 0;
	}
	if (sig == SIGQUIT)
		ft_putstr("\b\b  \b\b", STDOUT);
}

char		*skip_quotes(char *command, char c)
{
	while (*command != '\0' && *command != c)
	{
		if (*command == '\\')
			command = skip_bslash(command);
		else
			command += 1;
	}
	return (command);
}

int			are_quotes_balanced(char *command)
{
	if (*command == '\\')
		command = skip_bslash(command);
	while (*command != '\0')
	{
		if (*command == '\'')
			command = skip_quotes(command + 1, '\'');
		else if (*command == '\"')
			command = skip_quotes(command + 1, '\"');
		if (*command == '\0')
			return (0);
		else
			command += 1;
		if (*command == '\\')
			command = skip_bslash(command);
	}
	return (1);
}

int			has_unexpected_end(char *command, size_t command_len)
{
	char	*command_end;
	size_t	backslash_counter;

	if (command_len < 2)
		return (0);
	if (!(are_quotes_balanced(command)))
		return (1);
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

int			ends_with_backslash_newline(char *command, size_t command_len)
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

int			check_sytnax(char *command, size_t *command_len, int count)
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
	{
		ft_putstr("> ", STDOUT);
		return (1);
	}
	if ((ends_with_backslash_newline(command, *command_len)))
	{
		command[*command_len - 2] = '\0';
		*command_len = *command_len - 2;
		ft_putstr("> ", STDOUT);
		return (1);
	}
	return (do_read);
}

char		*read_command(void)
{
	int		count;
	char	buf[BUFFER_SIZE];
	char	command[BUFFER_SIZE];
	int		do_read;

	if ((signal(SIGINT, handle_signal)) == SIG_ERR)
		print_error(0, "Error: Cannot catch SIGINT");
	if ((signal(SIGQUIT, handle_signal)) == SIG_ERR)
		print_error(0, "Error: Cannot catch SIGQUIT");
	g_command_len = 0;
	do_read = 1;
	ft_putstr(PROMPT_STRING, STDOUT);
	while (do_read)
	{
		if ((count = read(STDIN, buf, BUFFER_SIZE - 1)) == -1)
		{
			print_error(0, strerror(errno));
			return (0);
		}
		buf[count] = '\0';
		ft_strlcpy(&command[g_command_len], buf,
				BUFFER_SIZE - g_command_len + count);
		g_command_len += count;
		if (g_command_len >= BUFFER_SIZE)
			break ;
		if ((do_read = check_sytnax(command, &g_command_len, count)) == -1)
			return (0);
	}
	return (insert_env_variables(command));
}

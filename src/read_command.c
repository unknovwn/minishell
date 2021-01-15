/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:12:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 13:33:52 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"
#include "check_syntax_errors.h"
#include "print_error.h"
#include <signal.h>

#define BUFFER_SIZE 262144

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\b\b  \b\b\n", STDOUT);
		exit(0);
	}
	if (sig == SIGQUIT)
		ft_putstr("\b\b  \b\b", STDOUT);
}

int		has_not_closed_pipe(char *command, size_t command_len)
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

int		ends_with_backslash_newline(char *command, size_t command_len)
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

int		check_sytnax_and_pipe(char *command, size_t *command_len, int count)
{
	char	*syntax_error;
	int		ctrld_flag;

	if ((ctrld_flag = (count == 0 || command[*command_len - 1] != '\n')))
	{
		ft_putstr("  \b\b", STDOUT);
		if (*command_len == 0)
			return (0);
		return (1);
	}
	if ((syntax_error = check_syntax_errors(command)))
		print_error_and_exit(syntax_error);
	if (has_not_closed_pipe(command, *command_len))
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
	return (ctrld_flag);
}

char	*read_command(void)
{
	int		count;
	char	command[BUFFER_SIZE];
	char	buf[BUFFER_SIZE];
	int		ctrld_flag;
	size_t	command_len;

	if ((signal(SIGINT, handle_signal)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGINT\n", SHELL_NAME);
	if ((signal(SIGQUIT, handle_signal)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGQUIT\n", SHELL_NAME);
	command_len = 0;
	ctrld_flag = 1;
	ft_putstr(PROMPT_STRING, STDOUT);
	while (ctrld_flag)
	{
		if ((count = read(0, buf, BUFFER_SIZE - 1)) == -1)
			return (0);
		buf[count] = '\0';
		ft_strlcpy(&command[command_len], buf,
				BUFFER_SIZE - (command_len + count));
		command_len += count;
		ctrld_flag = check_sytnax_and_pipe(command, &command_len, count);
	}
	return (insert_env_variables(command));
}

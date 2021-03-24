#include "minishell_macro.h"
#include "skipping.h"
#include "libft.h"

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
	if (backslash_counter % 2 == 0)
		ft_putstr("> ", STDOUT);
	return (backslash_counter % 2 == 0);
}

int			ends_with_backslash_newline(char *command, size_t *command_len)
{
	char	*command_end;
	size_t	backslash_counter;

	if (*command_len < 2)
		return (0);
	command_end = &(command[*command_len - 1]);
	if (*command_end != '\n')
		return (0);
	command_end--;
	backslash_counter = 0;
	while (command_end >= command && *command_end == '\\')
	{
		backslash_counter++;
		command_end--;
	}
	if (backslash_counter % 2 != 0)
	{
		command[*command_len - 2] = '\0';
		*command_len = *command_len - 2;
		ft_putstr("> ", STDOUT);
	}
	return (backslash_counter % 2 != 0);
}

#include "minishell_macro.h"
#include "libft.h"

void	print_error(char *command, char *error_string)
{
	if (command)
		ft_fprintf(STDERR, "%s: %s: %s\n", SHELL_NAME, command, error_string);
	else
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, error_string);
}

void	print_error_and_exit(int exit_code, char *command, char *error_string)
{
	print_error(command, error_string);
	exit(exit_code);
}

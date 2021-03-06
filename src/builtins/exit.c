#include "minishell.h"
#include "minishell_macro.h"
#include "libft.h"
#include "print_error.h"

#define COMMAND "exit"

int		is_number(char *s)
{
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (!(ft_isdigit(*s++)))
			return (0);
	}
	return (1);
}

int		exit_command(int argc, char **argv)
{
	ft_putstr("exit\n", STDOUT);
	if (argc == 1)
	{
		g_exit_code = 0;
		return (MINISHELL_EXIT);
	}
	if (!(is_number(argv[1])))
	{
		g_exit_code = 255;
		ft_fprintf(STDERR, "%s: %s: %s: numeric argument required\n",
				SHELL_NAME, COMMAND, argv[1]);
		return (MINISHELL_EXIT);
	}
	if (argc > 2)
	{
		print_error(COMMAND, "too many arguments");
		return (1);
	}
	g_exit_code = ft_atoi(argv[1]);
	return (MINISHELL_EXIT);
}

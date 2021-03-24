#include "minishell.h"
#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>
#include <signal.h>

t_list	*g_env;
int		g_exit_code;
int		g_sin;
int		g_sout;

void	handle_signal_exec(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr("Quit: 3", STDOUT);
	ft_putstr("\n", STDOUT);
}

void	parse_env_var(char *var)
{
	char	*equals_sign;
	char	*name;
	char	*value;

	if (!(equals_sign = ft_strchr(var, '=')))
	{
		clear_env();
		print_error_and_exit(1, 0, "error: invalid program environment");
	}
	*equals_sign = '\0';
	name = var;
	value = (equals_sign + 1);
	if ((add_env_var(name, value, 0)) == -1)
	{
		clear_env();
		print_error_and_exit(1, 0, strerror(errno));
	}
}

void	repl(void)
{
	char	*command;
	int		return_value;
	char	*ascii_return_value;

	while (1)
	{
		if (!(command = read_command()))
			continue ;
		if ((signal(SIGINT, handle_signal_exec)) == SIG_ERR)
			print_error(0, "Error: Cannot catch SIGINT");
		if ((signal(SIGQUIT, handle_signal_exec)) == SIG_ERR)
			print_error(0, "Error: Cannot catch SIGQUIT");
		return_value = execute(command);
		free(command);
		if (return_value == MINISHELL_EXIT)
			break ;
		if (!(ascii_return_value = ft_uitoa(return_value & 255)))
			continue ;
		set_new_value("?", ascii_return_value, 1);
		free(ascii_return_value);
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_exit_code = 0;
	if ((g_sin = dup(STDIN)) == -1)
		print_error_and_exit(1, 0, strerror(errno));
	if ((g_sout = dup(STDOUT)) == -1)
		print_error_and_exit(1, 0, strerror(errno));
	g_env = init_env();
	while (*envp)
		parse_env_var(*envp++);
	repl();
	clear_env();
	return (g_exit_code);
}

#include "minishell.h"
#include "minishell_macro.h"
#include "super_split.h"
#include "print_error.h"
#include "libft.h"
#include "execute_one.h"
#include "env_utils.h"
#include <sys/errno.h>
#include <string.h>

int		is_s_semicolon(char *c)
{
	return (*c == ';');
}

int		execute_commands(char **commands)
{
	int ret;
	int i;

	i = 0;
	while (commands[i])
	{
		if ((ret = execute_one(commands[i])) == -1)
		{
			if (errno)
				ft_fprintf(STDOUT, "%s: %s\n", SHELL_NAME, strerror(errno));
		}
		i++;
	}
	free_string_arr(commands);
	return (ret);
}

int		execute(char *command)
{
	char	**commands;
	int		ret;

	if (ft_strlen(command) == 0)
	{
		ft_putstr("exit\n", STDOUT);
		return (MINISHELL_EXIT);
	}
	command[ft_strlen(command) - 1] = '\0';
	if (!(commands = super_split(command, is_s_semicolon, 1)))
	{
		print_error(0, strerror(errno));
		return (1);
	}
	if ((ret = execute_commands(commands)) == -1)
		ret = 1;
	return (ret);
}

#include "minishell.h"
#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"

#define COMMAND "unset"

int		unset_command(int argc, char **argv)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (!(is_valid_name(argv[i])))
		{
			ft_fprintf(STDERR, "%s: %s: `%s\': not a valid identifier\n",
					SHELL_NAME, COMMAND, argv[i++]);
			ret = 1;
			continue ;
		}
		remove_var_from_env(argv[i++]);
	}
	return (ret);
}

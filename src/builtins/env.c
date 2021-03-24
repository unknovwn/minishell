#include "minishell.h"
#include "minishell_macro.h"
#include "env_utils.h"
#include "libft.h"

int		env_command(void)
{
	t_list	*g_env_p;
	char	*name;
	char	*value;

	g_env_p = g_env;
	while (g_env_p)
	{
		name = ((t_env_variable*)(g_env_p->content))->name;
		value = ((t_env_variable*)(g_env_p->content))->value;
		if ((ft_strcmp(name, "?")) != 0 && value)
			ft_fprintf(STDOUT, "%s=%s\n", name, value);
		g_env_p = g_env_p->next;
	}
	return (0);
}

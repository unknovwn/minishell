#include "env_utils.h"
#include "minishell_macro.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>

void			delete_env_var(void *env_var)
{
	t_env_variable	*env_var_p;

	env_var_p = (t_env_variable*)env_var;
	free(env_var_p->name);
	if (env_var_p->value)
		free(env_var_p->value);
	free(env_var_p);
}

void			remove_var_from_env(char *name)
{
	t_list	*prev;
	t_list	*curr;

	prev = 0;
	curr = g_env;
	while (curr)
	{
		if ((ft_strcmp(((t_env_variable*)(curr->content))->name, name)) == 0)
		{
			if (!prev)
				g_env = curr->next;
			else
				prev->next = curr->next;
			ft_lstdelone(curr, delete_env_var);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char			*get_var_value(char *name)
{
	t_list	*g_env_p;

	g_env_p = g_env;
	while (g_env_p)
	{
		if ((ft_strcmp(((t_env_variable*)(g_env_p->content))->name, name)) == 0)
			return (((t_env_variable*)(g_env_p->content))->value);
		g_env_p = g_env_p->next;
	}
	return (0);
}

t_env_variable	*create_env_var(char *name, char *value, int shell_only)
{
	t_env_variable	*env_var;
	char			*var_name;
	char			*var_value;

	if (!(var_name = ft_strdup(name)))
		return (0);
	if (!value)
		var_value = 0;
	else if (!(var_value = ft_strdup(value)))
	{
		free(var_name);
		return (0);
	}
	if (!(env_var = (t_env_variable *)malloc(sizeof(t_env_variable))))
	{
		free(var_name);
		if (var_value)
			free(var_value);
		return (0);
	}
	env_var->name = var_name;
	env_var->value = var_value;
	env_var->shell_only = shell_only;
	return (env_var);
}

int				add_env_var(char *name, char *value, int shell_only)
{
	t_list			*list_elem;
	t_env_variable	*env_var;

	if (!(env_var = create_env_var(name, value, shell_only)))
	{
		print_error(0, strerror(errno));
		return (-1);
	}
	if (!(list_elem = ft_lstnew(env_var)))
	{
		delete_env_var(env_var);
		print_error(0, strerror(errno));
		return (-1);
	}
	ft_lstadd_back(&g_env, list_elem);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:16:13 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 22:18:12 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "minishell_macro.h"
#include <sys/errno.h>
#include <string.h>

void			delete_env_var(void *env_var)
{
	t_env_variable	*env_var_p;

	env_var_p = (t_env_variable*)env_var;
	free(env_var_p->name);
	free(env_var_p->value);
	free(env_var_p);
}

void			remove_var_from_env(char *name)
{
	t_list	*prev;
	t_list	*curr;

	prev = g_env;
	while ((curr = prev->next))
	{
		if ((ft_strcmp(((t_env_variable*)(curr->content))->name, name)) == 0)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, delete_env_var);
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

t_env_variable	*create_env_var(char *name, char *value)
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
		free(var_value);
		return (0);
	}
	env_var->name = var_name;
	env_var->value = var_value;
	return (env_var);
}

int				add_env_var(char *name, char *value)
{
	t_list			*list_elem;
	t_env_variable	*env_var;

	if (!(env_var = create_env_var(name, value)))
	{
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		return (-1);
	}
	if (!(list_elem = ft_lstnew(env_var)))
	{
		delete_env_var(env_var);
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		return (-1);
	}
	ft_lstadd_back(&g_env, list_elem);
	return (0);
}

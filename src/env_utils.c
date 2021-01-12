/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:16:13 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/12 22:07:09 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			delete_env_var(void *env_var)
{
	t_env_variable	*env_var_p;
	env_var_p = (t_env_variable*)env_var;
	free(env_var_p->name);
	free(env_var_p->value);
	free(env_var_p);
}

void			clear_env()
{
	ft_lstclear(&g_env, delete_env_var);
}

char			*get_env_value(char *name)
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

	if (!(name = ft_strdup(name)))
		return (0);
	if (!(value = ft_strdup(value)))
	{
		free(name);
		return (0);
	}
	if (!(env_var = (t_env_variable *)malloc(sizeof(t_env_variable))))
	{
		free(name);
		free(value);
		return (0);
	}
	env_var->name = name;
	env_var->value = value;
	return (env_var);
}

void		add_env_var(char *name, char *value)
{
	t_list			*list_elem;
	t_env_variable	*env_var;

	if (!(env_var = create_env_var(name, value)))
	{
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		return ;
	}
	if (!(list_elem = ft_lstnew(env_var)))
	{
		delete_env_var(env_var);
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		return ;
	}
	ft_lstadd_back(&g_env, list_elem);
}

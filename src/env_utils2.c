/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:01:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/16 16:33:32 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "libft.h"
#include "minishell_macro.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>

void		clear_env(void)
{
	ft_lstclear(&g_env, delete_env_var);
}

void		parse_env_var(char *var)
{
	char	*equals_sign;
	char	*name;
	char	*value;

	if (!(equals_sign = ft_strchr(var, '=')))
	{
		clear_env();
		print_error_and_exit(1, "error: invalid program environment");
	}
	*equals_sign = '\0';
	name = var;
	value = (equals_sign + 1);
	if ((add_env_var(name, value)) == -1)
	{
		clear_env();
		print_error_and_exit(1, strerror(errno));
	}
}

t_list		*init_env(void)
{
	t_env_variable	*last_return_value;
	t_list			*env;

	if (!(last_return_value = create_env_var("?", "0")))
		print_error_and_exit(1, strerror(errno));
	if (!(env = ft_lstnew(last_return_value)))
	{
		delete_env_var(last_return_value);
		print_error_and_exit(1, strerror(errno));
	}
	return (env);
}

int			is_valid_name(char *name)
{
	int		i;

	if (ft_isdigit(name[0]))
		return (0);
	i = 0;
	while (name[i])
	{
		if (!(ft_isalpha(name[i])) && !(ft_isdigit(name[i]))
				&& (name[i] != '_'))
			return (0);
		i++;
	}
	return (i != 0);
}

int			set_new_value(char *name, char *value)
{
	t_list	*g_env_p;
	char	*new_value;

	if (!(new_value = ft_strdup(value)))
	{
		ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		return (-1);
	}
	g_env_p = g_env;
	while (g_env_p)
	{
		if ((ft_strcmp(((t_env_variable*)(g_env_p->content))->name, name)) == 0)
		{
			free(((t_env_variable*)(g_env_p->content))->value);
			((t_env_variable*)(g_env_p->content))->value = new_value;
			return (0);
		}
		g_env_p = g_env_p->next;
	}
	free(new_value);
	return (add_env_var(name, value));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:01:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 21:26:52 by mgeneviv         ###   ########.fr       */
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
		print_error_and_exit("error: invalid program environment");
	}
	*equals_sign = '\0';
	name = var;
	value = (equals_sign + 1);
	if ((add_env_var(name, value)) == -1)
	{
		clear_env();
		print_error_and_exit(strerror(errno));
	}
}

t_list		*init_env(void)
{
	t_env_variable	*last_return_value;
	t_list			*env;

	if (!(last_return_value = create_env_var("?", "0")))
		print_error_and_exit(strerror(errno));
	if (!(env = ft_lstnew(last_return_value)))
	{
		delete_env_var(last_return_value);
		print_error_and_exit(strerror(errno));
	}
	return (env);
}

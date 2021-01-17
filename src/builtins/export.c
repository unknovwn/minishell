/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:28:51 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:07:20 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "libft.h"
#include "env_utils.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>

#define COMMAND "export"

char	**sort_names(void)
{
	char	**names;
	t_list	*g_env_p;
	int		i;

	if (!(names = (char**)malloc(sizeof(char*) * (ft_lstsize(g_env) + 1))))
	{
		print_error(COMMAND, strerror(errno));
		return (0);
	}
	g_env_p = g_env;
	i = 0;
	while (g_env_p)
	{
		names[i++] = ((t_env_variable*)(g_env_p->content))->name;
		g_env_p = g_env_p->next;
	}
	names[i] = 0;
	return (ft_sort_string_arr(names));
}

int		print_sorted_env(void)
{
	char	**sorted_names;
	int		i;
	char	*value;

	if (!(sorted_names = sort_names()))
		return (1);
	i = 0;
	while (sorted_names[i])
	{
		if ((ft_strcmp(sorted_names[i], "?")) != 0)
		{
			value = get_var_value(sorted_names[i]);
			ft_fprintf(STDOUT, "declare -x %s", sorted_names[i]);
			if (value)
				ft_fprintf(STDOUT, "=\"%s\"", value);
			ft_putstr("\n", STDOUT);
		}
		i++;
	}
	free(sorted_names);
	return (0);
}

int		add_var(char *assignment, int shell_only)
{
	char	*equals_sign;
	char	*name;
	char	*value;
	int		has_value;

	has_value = 1;
	if (!(equals_sign = ft_strchr(assignment, '=')))
		has_value = 0;
	*equals_sign = '\0';
	name = assignment;
	if (!(is_valid_name(name)))
	{
		*equals_sign = '=';
		ft_fprintf(STDERR, "%s: `%s\': %s: not a valid identifier\n",
				SHELL_NAME, COMMAND, assignment);
		return (-1);
	}
	if (has_value)
		value = (equals_sign + 1);
	else
		value = 0;
	return (set_new_value(name, value, shell_only));
}

int		export_command(int argc, char **argv, int shell_only)
{
	int	i;
	int	ret;

	i = (ft_strcmp(argv[0], "export") == 0);
	if (argc == 1 && i == 1)
		return (print_sorted_env());
	ret = 0;
	while (i < argc)
	{
		if ((add_var(argv[i++], shell_only)) == -1)
			ret = 1;
	}
	return (ret);
}

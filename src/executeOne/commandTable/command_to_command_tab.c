/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_command_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:17:45 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 20:26:19 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_table.h"
#include "split_str.h"
#include "utils.h"

static int	set_redirect(t_command *cell, t_split_str s)
{
	if (is_redirect_from(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_from(cell, s)) != 0)
			return (-1);
	}
	else if (is_redirect_double_to(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_double_to(cell, s)) != 0)
			return (-1);
	}
	else if (is_redirect_to(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_to(cell, s)) != 0)
			return (-1);
	}
	return (0);
}

static int	set_redirects(t_command *cell, char *command)
{
	t_split_str	s;

	init_str(&s, command, is_redirect_or_space);
	while (*s.current != '\0')
	{
		split_skip_space(&s);
		if (is_redirect(s.current))
		{
			if (set_redirect(cell, s) != 0)
				return (-1);
			skip_sep(&s);
		}
		skip_string(&s);
	}
	return (0);
}

int			commands_to_command_tab(t_command_tab *tab, char **commands)
{
	size_t		i;

	i = 0;
	while (i < tab->len)
	{
		if ((tab->cells[i].argv = split_argv(commands[i])) == NULL)
			return (-1);
		if (set_redirects(&(tab->cells[i]), commands[i]) != 0)
			return (-1);
		i += 1;
	}
	return (0);
}

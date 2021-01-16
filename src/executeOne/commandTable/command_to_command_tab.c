/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_command_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:17:45 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 13:17:47 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "command_table.h"
#include "../super_split.h"
#include "../split_str.h"
#include "../libft.h"
#include "../skipping.h"

void	split_str_skip_space(t_split_str *s)
{
	s->current = skip_space(s->current);
	s->after_protecting = skip_protected(s->current);
}


int		commands_to_command_tab(t_command_tab *tab, char **commands)
{
	t_split_str	s;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < tab->len)
	{
		if ((tab->cells[i].argv = split_argv(commands[i])) == NULL)
			return (-1);
		init_str(&s, commands[i], is_redirect_or_space);
		while (*s.current != '\0')
		{
			split_str_skip_space(&s);
			if (is_redirect_from(s.current))
			{
				skip_sep(&s);
				if ((set_redirect_from(&(tab->cells[i]), s)) != 0)
					return (-1);
			}
			else if (is_redirect_double_to(s.current))
			{
				skip_sep(&s);
				if ((set_redirect_double_to(&(tab->cells[i]), s)) != 0)
					return (-1);
			}
			else if (is_redirect_to(s.current))
			{
				skip_sep(&s);
				if ((set_redirect_to(&(tab->cells[i]), s)) != 0)
					return (-1);
			}
			skip_string(&s);
		}
		i += 1;
	}
	return (0);
}

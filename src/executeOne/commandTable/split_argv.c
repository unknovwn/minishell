/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:49:08 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 00:49:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_table.h"
#include "../split_str.h"
#include "../skipping.h"

static size_t	count_args(char *command)
{
	t_split_str	s;
	size_t		len;

	init_str(&s, command, is_redirect_or_space);
	len = 0;
	while (*s.current != '\0')
	{
		split_skip_space(&s);
		if (*s.current == '\0')
			break ;
		if (is_sep(&s))
		{
			skip_sep(&s);
			skip_string(&s);
			continue ;
		}
		len += 1;
		skip_string(&s);
	}
	return (len);
}

char			**split_argv(char *command)
{
	t_split_str	s;
	char		**argv;
	size_t		len;
	size_t		i;

	len = count_args(command);
	if ((argv = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	argv[len] = NULL;
	init_str(&s, command, is_redirect_or_space);
	i = 0;
	while (i < len)
	{
		split_skip_space(&s);
		if (is_sep(&s))
		{
			skip_sep(&s);
			skip_string(&s);
			continue ;
		}
		if ((argv[i] = copy_and_skip_string(&s)) == NULL)
			return (NULL);
		i += 1;
	}
	return (argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:49:08 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 20:27:00 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "command_table.h"
#include "split_str.h"
#include "skipping.h"
#include "libft.h"

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

static int		copy_argv(char **argv, size_t len, t_split_str s)
{
	size_t	i;

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
			return (-1);
		i += 1;
	}
	return (0);
}

char			**split_argv(char *command)
{
	t_split_str	s;
	char		**argv;
	size_t		len;

	len = count_args(command);
	if ((argv = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	argv[len] = NULL;
	init_str(&s, command, is_redirect_or_space);
	if (copy_argv(argv, len, s) != 0)
	{
		free_string_arr(argv);
		return (NULL);
	}
	return (argv);
}

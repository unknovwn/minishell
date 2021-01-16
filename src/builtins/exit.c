/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:19:27 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 21:49:16 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "libft.h"

#define COMMAND "exit"

int		is_number(char *s)
{
	while (*s)
	{
		if (!(ft_isdigit(*s++)))
			return (0);
	}
	return (1);
}

int		exit_command(int argc, char **argv)
{
	ft_putstr("exit\n", STDOUT);
	if (argc == 1)
	{
		g_exit_code = 0;
		return (0);
	}
	if (!(is_number(argv[1])))
	{
		ft_fprintf(STDERR, "%s: %s: %s: numeric argument required\n",
				SHELL_NAME, COMMAND, argv[1]);
		g_exit_code = 255;
		return (0);
	}
	if (argc > 2)
	{
		ft_fprintf(STDERR, "%s: %s: too many arguments\n", SHELL_NAME, COMMAND);
		return (1);
	}
	g_exit_code = ft_atoi(argv[1]) & 255;
	return (0);
}
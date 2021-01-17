/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:16:45 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:34:30 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_macro.h"
#include "super_split.h"
#include "print_error.h"
#include "libft.h"
#include "execute_one.h"
#include "env_utils.h"
#include <sys/errno.h>
#include <string.h>

int		is_s_semicolon(char *c)
{
	return (*c == ';');
}

int		execute(char *command)
{
	char	**commands;
	int		i;
	int		ret;

	ret = 0;
	if (ft_strlen(command) == 0 || ft_strcmp(command, "exit\n") == 0)
	{
		ft_putstr("exit\n", STDOUT);
		return (MINISHELL_EXIT);
	}
	command[ft_strlen(command) - 1] = '\0';
	if (!(commands = super_split(command, is_s_semicolon)))
	{
		print_error(0, strerror(errno));
		return (1);
	}
	i = 0;
	while (commands[i])
	{
		if ((ret = execute_one(*commands)) == -1)
		{
			if (errno)
				ft_fprintf(STDOUT, "%s: %s\n", SHELL_NAME, strerror(errno));
		}
		i++;
	}
	free_string_arr(commands);
	if (ret == -1)
		ret = 1;
	return (ret);
}

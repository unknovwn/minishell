/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:52:07 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 13:30:00 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include <sys/errno.h>
#include <string.h>
#include "minishell_macro.h"

#define COMMAND "cd"

int	cd_command(int argc, char **argv)
{
	char	*path;

	path = argv[1];
	if (argc == 1)
		path = get_var_value("HOME");
	if (!path)
	{
		ft_fprintf(STDERR, "%s: %s: %s\n",
				SHELL_NAME, COMMAND, "HOME not set");
		return (1);
	}
	if ((chdir(path)) == -1)
	{
		ft_fprintf(STDERR, "%s: %s: %s: %s\n",
				SHELL_NAME, COMMAND, path, strerror(errno));
		return (1);
	}
	return (0);
}

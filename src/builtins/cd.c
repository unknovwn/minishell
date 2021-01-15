/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:52:07 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 19:23:41 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

int		cd_command(int argc, char **argv)
{
	char	*path;

	path = argv[1];
	if (argc == 1)
		path = get_var_value("HOME");
	return (chdir(path) == -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:05:37 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 20:05:46 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "execute_command_tab.h"

int			execute_one(char *command)
{
	t_command_tab	*tab;
	int				ret;

	if ((tab = parse_command(command)) == NULL)
		return (-1);
	ret = execute_command_tab(tab);
	del_command_tab(&tab);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:16:49 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/16 16:52:31 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "libft.h"

int		echo_command(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i > 1)
			ft_putstr(" ", STDOUT);
		ft_putstr(argv[i++], STDOUT);
	}
	if (!(argc > 1 && (ft_strcmp(argv[1], "-n") == 0)))
		ft_putstr("\n", STDOUT);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:18:25 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 18:18:28 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "libft.h"

int		echo_command(int argc, char **argv)
{
	int	i;
	int	newline;

	newline = !(argc > 1 && (ft_strcmp(argv[1], "-n") == 0));
	i = 1 + !newline;
	while (i < argc)
	{
		if (i > 1)
			ft_putstr(" ", STDOUT);
		ft_putstr(argv[i++], STDOUT);
	}
	if (newline)
		ft_putstr("\n", STDOUT);
	return (0);
}

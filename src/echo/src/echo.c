/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:56:19 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/09 20:56:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	size_t	i;
	size_t	j;
	i = 1;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		argc -= 1;
		i = 2;
	}
	while (argc > 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &(argv[i][j]), 1);
			j += 1;
		}
		if (argc - 1 > 1)
			write(1, " ", 1);
		i += 1;
		argc -= 1;
	}
	if (ft_strcmp(argv[1], "-n") != 0)
		write(1, "\n", 1);
	return (0);
}

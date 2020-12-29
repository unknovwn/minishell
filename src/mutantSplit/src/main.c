/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:24:21 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:07:25 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "split_commands.h"

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	split_commands(argv[1], ';');
	return (0);
}

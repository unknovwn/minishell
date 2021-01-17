/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:04:09 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/12 20:05:01 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../execute_one.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("No args for main\n");
		return (0);
	}
	execute_one(argv[1]);
	return (0);
}

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

#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

#include "echo.h"
#include "libft.h"

static void	exit_with_printing_newline(void)
{
	write(1, "\n", 1);
	exit(0);
}

static void	exit_with_allocation_error(void)
{
	write(2, "Error: can't alloacte memory\n", 29);
	exit(errno);
}

static int	check_newline_flag(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (0);
	else
		return (1);
}

int			main(int argc, char **argv)
{
	t_printing	printing;

	if (argc < 2)
		exit_with_printing_newline();
	printing.newline_flag = check_newline_flag(argv[1]);
	if (argc == 2 && printing.newline_flag == 0)
		exit(0);
	else if (printing.newline_flag == 0)
		printing.buff = set_args_to_buff(argc - 2, argv + 2,
										printing.newline_flag);
	else
		printing.buff = set_args_to_buff(argc - 1, argv + 1,
										printing.newline_flag);
	if (printing.buff == NULL)
		exit_with_allocation_error();
	else
		ft_putstr(printing.buff, 1);
	free(printing.buff);
	return (0);
}

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
#include <stdlib.h>
#include <stdbool.h>
#include <sys/errno.h>

#include "echo.h"
#include "libft.h"

void		exit_with_printing_newline(void)
{
	write(1, "\n", 1);
	exit(0);
}

void		exit_with_allocation_error(void)
{
	write(2, "Error: can't alloacte memory\n", 29);
	exit(errno);
}

size_t		count_args_len(t_printing printing)
{
	size_t	i;
	size_t	len;

	len = 0;
	printf("cur: |%s|\n", *printing.current);
	while (printing.argc != 0)
	{
		i = 0;
		while ((*printing.current)[i] != '\0')
		{
			len += 1;
			i += 1;
		}
		printing.current += 1;
		printing.argc -= 1;
		if (printing.argc - 1 > 0)
			len += 1;
	}
	return (len);
}

t_printing	*init_with_newline_flag(int argc, char **argv)
{
	t_printing	*printing;

	if (argc == 2)
		exit_with_printing_newline();
	printing = (t_printing*)malloc(sizeof(t_printing));
	if (printing == NULL)
		exit_with_allocation_error();
	printing->newline_flag = 1;
	printing->args = argv + 2;
	printing->argc = argc - 2;
	printing->current = printing->args;
	printing->buff_len = count_args_len(*printing);
	printing->buff = (char*)malloc(sizeof(char) * (printing->buff_len + 1));
	if (printing->buff == NULL)
	{
		free(printing);
		exit_with_allocation_error();
	}
	printing->buff[printing->buff_len] = '\0';
	return (printing);
}

t_printing	*init_without_newline_flag(int argc, char **argv)
{
	t_printing	*printing;

	printing = (t_printing*)malloc(sizeof(t_printing));
	if (printing == NULL)
		exit_with_allocation_error();
	printing->newline_flag = 0;
	printing->args = argv + 1;
	printing->argc = argc - 1;
	printing->current = printing->args;
	printing->buff_len = count_args_len(*printing);
	printing->buff = (char*)malloc(sizeof(char) * (printing->buff_len + 1));
	if (printing->buff == NULL)
	{
		free(printing);
		exit_with_allocation_error();
	}
	printing->buff[printing->buff_len] = '\0';
	return (printing);
}

t_printing	*init_printing(int argc, char **argv)
{
	t_printing	*printing;

	if (ft_strcmp(argv[1], "-n") == 0)
		printing = init_with_newline_flag(argc, argv);
	else
		printing = init_without_newline_flag(argc, argv);
	return (printing);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		exit_with_printing_newline();

	size_t	i;
	size_t	j;
	t_printing	*printing = init_printing(argc, argv);

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

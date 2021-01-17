/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:02:20 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:07:05 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_macro.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>

#define COMMAND "pwd"

char	*create_buf(char *buf, size_t size)
{
	int		i;

	i = 0;
	while (!(buf = getcwd(buf, size)) && i < 10)
	{
		size *= 2;
		free(buf);
		if (!(buf = (char*)malloc(sizeof(char) * size)))
		{
			print_error(COMMAND, strerror(errno));
			return (0);
		}
		i++;
	}
	if (i == 10)
	{
		print_error(COMMAND, "cannot write pwd to buffer");
		return (0);
	}
	return (buf);
}

int		pwd_command(void)
{
	size_t	size;
	char	*buf;

	size = 1024;
	if (!(buf = (char*)malloc(sizeof(char) * size)))
	{
		print_error(COMMAND, strerror(errno));
		return (1);
	}
	if (!(buf = create_buf(buf, size)))
		return (1);
	ft_fprintf(STDOUT, "%s\n", buf);
	free(buf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:02:20 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 20:04:00 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_macro.h"

int		pwd_command(void)
{
	char	*buf;
	size_t	size;
	int		i;

	size = 1024;
	if (!(buf = (char*)malloc(sizeof(char) * size)))
		return (1);
	i = 0;
	while (!(buf = getcwd(buf, size)) && i < 10)
	{
		size *= 2;
		free(buf);
		if (!(buf = (char*)malloc(sizeof(char) * size)))
			return (1);
		i++;
	}
	if (i == 9)
		return (1);
	ft_fprintf(STDOUT, "%s\n", buf);
	free(buf);
	return (0);
}

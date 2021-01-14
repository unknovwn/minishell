/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:50:14 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 17:50:16 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "files.h"
#include "../commandTable/command_table.h"

void	del_fds(t_files *files)
{
	if (files->fds != NULL)
		free(files->fds);
	files->fds = NULL;
	files->len = 0;
	return ;
}

int		open_files(t_files *files, char **names)
{
	size_t	len;
	size_t	i;

	files->fds = (int*)malloc(sizeof(int) * files->len);
	if (files->fds == NULL)
		return (-1);
	i = 0;
	while (names[i] != NULL)
	{
		files->fds[i] = open(names[i], O_RDONLY);
		if (files->fds[i] < 0)
		{
			del_fds(files);
			return (-1);
		}
		else
			i += 1;
	}
	return (0);
}

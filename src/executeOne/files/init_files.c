/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:55:37 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 17:55:39 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "files.h"

void	del_files(t_files **files)
{
	if ((*files)->fds != NULL)
		free((*files)->fds);
	(*files)->fds = NULL;
	free(*files);
	*files = NULL;
}

t_files	*init_files(void)
{
	t_files	*files;

	files = (t_files*)malloc(sizeof(t_files));
	if (files == NULL)
		return (NULL);
	files->fds = NULL;
	files->len = 0;
	return (files);
}

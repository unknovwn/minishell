/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:50:51 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 17:50:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <stdlib.h>

typedef struct	s_files
{
	int			*fds;
	size_t		len;
}				t_files;

t_files			*init_files(void);
void			del_files(t_files **files);

int				open_files(t_files *files, char **names);
void			del_fds(t_files *files);

#endif

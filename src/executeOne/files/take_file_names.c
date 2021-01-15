/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_file_names.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:32:09 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/15 18:32:12 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commandTable/command_table.h"
#include "../super_split.h"
#include "../split_str.h"
#include "../skipping.h"
#include "../libft.h"

static char	*take_file_name(char *str)
{
	char		*name;
	t_split_str	s;

	init_str(&s, str, is_redirect_or_space);
	s.current = skip_space(s.current);
	s.after_protecting = skip_protected(s.current);
	if ((name = copy_and_skip_string(&s)) == NULL)
			return (NULL);
	return (name);
}

char		**take_file_names(char **by_from)
{
	char	**file_names;
	size_t	len;
	size_t	i;

	len = count_strs(by_from);
	if ((file_names = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	file_names[len] = NULL;
	i = 0;
	while (by_from[i] != NULL)
	{
		if ((file_names[i] = take_file_name(by_from[i])) == NULL)
		{
			free_string_arr(file_names);
			return (NULL);
		}
		i += 1;
	}
	return (file_names);
}

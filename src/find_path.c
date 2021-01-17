/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:42:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/17 20:32:51 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "super_split.h"
#include "env_utils.h"
#include <sys/errno.h>
#include <string.h>
#include "print_error.h"

int		dir_has_file(char *path, char *command)
{
	DIR				*dirp;
	struct dirent	*dp;

	if (!(dirp = opendir(path)))
		return (-1);
	while ((dp = readdir(dirp)))
	{
		if ((ft_strcmp(dp->d_name, command)) == 0)
		{
			closedir(dirp);
			return (1);
		}
	}
	closedir(dirp);
	return (0);
}

int		is_s_colon(char *c)
{
	return (*c == ':');
}

char	*find_path(char *command)
{
	char	**paths;
	char	*result;
	int		is_found;
	int		i;
	size_t	result_len;

	if (!(paths = super_split(get_var_value("PATH"), is_s_colon)))
		print_error_and_exit(1, 0, strerror(errno));
	i = 0;
	while (paths[i])
	{
		if ((is_found = dir_has_file(paths[i], command)) == 1)
		{
			result_len = ft_strlen(paths[i]) + ft_strlen(command) + 1;
			if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
			{
				free_string_arr(paths);
				print_error_and_exit(1, 0, strerror(errno));
			}
			ft_strlcpy(result, paths[i], result_len + 1);
			ft_strncat(result, "/", 1);
			ft_strncat(result, command, ft_strlen(command));
			free_string_arr(paths);
			return (result);
		}
		else if (is_found == -1)
		{
			free_string_arr(paths);
			print_error_and_exit(1, 0, strerror(errno));
		}
		i++;
	}
	free_string_arr(paths);
	return (0);
}

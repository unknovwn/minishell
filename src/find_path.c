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

int		is_colon(char *c)
{
	return (*c == ':');
}

char	*create_full_path(char *path, char *command)
{
	char	*result;
	size_t	result_len;

	result_len = ft_strlen(path) + ft_strlen(command) + 1;
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	ft_strlcpy(result, path, result_len + 1);
	ft_strncat(result, "/", 1);
	ft_strncat(result, command, ft_strlen(command));
	return (result);
}

char	*find_path(char *command)
{
	char	**paths;
	int		i;
	char	*path;
	char	*result;

	if (!(path = get_var_value("PATH")))
		return (0);
	if (!(paths = super_split(path, is_colon, 0)))
		print_error_and_exit(1, 0, strerror(errno));
	i = 0;
	while (paths[i])
	{
		if ((dir_has_file(paths[i], command)) == 1)
		{
			result = create_full_path(paths[i], command);
			free_string_arr(paths);
			if (!result)
				print_error_and_exit(1, 0, strerror(errno));
			return (result);
		}
		i++;
	}
	free_string_arr(paths);
	return (0);
}

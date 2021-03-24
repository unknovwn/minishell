#include "insert_env_variables_utils.h"
#include "print_error.h"
#include <sys/errno.h>
#include <string.h>

char	*malloc_result(char *command)
{
	char	*result;
	size_t	result_len;

	if ((result_len = count_result_len(command)) == -1)
		return (0);
	if (!(result = (char*)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	result[0] = '\0';
	return (result);
}

char	*insert_env_variables(char *command)
{
	int		i;
	char	*result;

	if (!(result = malloc_result(command)))
	{
		print_error(0, strerror(errno));
		return (0);
	}
	i = 0;
	while (command[i])
	{
		if ((i = iterate_loop(result, command, i)) == -1)
		{
			free(result);
			print_error(0, strerror(errno));
			return (0);
		}
	}
	return (result);
}

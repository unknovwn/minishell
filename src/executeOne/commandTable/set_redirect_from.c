#include <unistd.h>
#include <fcntl.h>

#include "command_table.h"
#include "split_str.h"

int				set_redirect_from(t_command *cell, t_split_str s)
{
	char	*file;

	if ((file = copy_and_skip_string(&s)) == NULL)
		return (-1);
	if (cell->in != 0)
	{
		if (close(cell->in) < 0)
		{
			free(file);
			return (-1);
		}
	}
	if ((cell->in = open(file, O_RDONLY)) < 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

#include <unistd.h>
#include <fcntl.h>

#include "command_table.h"
#include "split_str.h"

int			set_redirect_double_to(t_command *cell, t_split_str s)
{
	char	*file;

	if ((file = copy_and_skip_string(&s)) == NULL)
		return (-1);
	if (cell->out != STDOUT)
	{
		if (close(cell->out) < 0)
		{
			free(file);
			return (-1);
		}
	}
	if ((cell->out = open(file, O_CREAT | O_WRONLY | O_APPEND,
								S_IREAD | S_IWRITE | S_IRGRP | S_IROTH)) < 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

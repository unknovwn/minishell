#include <stdlib.h>

#include "command_table.h"
#include "libft.h"

void			del_command_tab(t_command_tab **tab)
{
	size_t	i;

	if ((*tab)->cells != NULL)
	{
		i = 0;
		while (i < (*tab)->len)
		{
			free_string_arr((*tab)->cells[i].argv);
			i += 1;
		}
		free((*tab)->cells);
	}
	(*tab)->cells = NULL;
	free(*tab);
	*tab = NULL;
}

t_command_tab	*init_command_tab(void)
{
	t_command_tab	*tab;

	tab = (t_command_tab*)malloc(sizeof(t_command_tab));
	if (tab == NULL)
		return (NULL);
	tab->cells = NULL;
	tab->len = 0;
	return (tab);
}

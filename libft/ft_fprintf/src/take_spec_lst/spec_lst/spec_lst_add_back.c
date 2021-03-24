#include <stdio.h>
#include <unistd.h>
#include "ft_fprintf.h"

/*
**	Function creates element of list, wich is described in "ft_printf.h",
**	and setup 0, '\0' or NULL for all properties.
**	Then adds it to the end of the list.
*/

t_spec_info	*spec_lst_add_back(t_spec_info **begin_lst, char *spec_position)
{
	t_spec_info	*tmp;

	tmp = (*begin_lst);
	if (tmp == NULL)
	{
		if (((*begin_lst) = spec_lst_create()) == NULL)
			return (NULL);
		(*begin_lst)->spec_ptr = spec_position;
		return (*begin_lst);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	if ((tmp->next = spec_lst_create()) == NULL)
		return (NULL);
	tmp->next->spec_ptr = spec_position;
	return (tmp->next);
}

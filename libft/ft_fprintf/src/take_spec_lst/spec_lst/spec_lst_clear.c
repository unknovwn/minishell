#include "ft_fprintf.h"

/*
**	Function removes list.
*/

t_spec_info	*spec_lst_clear(t_spec_info **begin_lst)
{
	t_spec_info	*tmp;

	if ((*begin_lst) == NULL)
		return (NULL);
	while ((*begin_lst) != NULL)
	{
		tmp = (*begin_lst);
		(*begin_lst) = (**begin_lst).next;
		if (tmp->arg != NULL)
			free(tmp->arg);
		free(tmp);
	}
	(*begin_lst) = NULL;
	return (NULL);
}

/*
**	Function works like strlen (man strlen),
*/

#include "ft_fprintf.h"

size_t		ft_prf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

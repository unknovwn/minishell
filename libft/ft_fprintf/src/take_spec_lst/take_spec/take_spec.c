/*
**	Puts 'type'(d, i, s, p ...) to lst->spec.
*/

#include <stdlib.h>
#include "ft_fprintf.h"

char	*take_spec(char *s, t_spec_info *lst)
{
	while (*s != '\0' && is_flag(*s))
		s++;
	lst->spec = (*s);
	if (*s != '\0')
		return (++s);
	else
		return (s);
}

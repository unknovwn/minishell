#include "split_str.h"
#include "libft.h"

void		split_skip_space(t_split_str *s)
{
	while (ft_s_isspace(s->current))
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
}

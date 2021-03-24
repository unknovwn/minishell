#include "split_str.h"

char		*sup_skip_bslash(char *s)
{
	if (*(s + 1) != '\0')
		s += 2;
	else
		s += 1;
	return (s);
}

int			is_sep(t_split_str *s)
{
	return (s->delim_comparator(s->current));
}

static int	is_sep_and_is_not_end(t_split_str *s)
{
	return (is_sep(s) && *s->current != '\0');
}

void		skip_sep(t_split_str *s)
{
	while (is_sep_and_is_not_end(s))
	{
		s->current += s->delim_comparator(s->current);
	}
	s->after_protecting = skip_protected(s->current);
}

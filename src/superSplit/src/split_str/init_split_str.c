#include "split_str.h"

void	init_str(t_split_str *str, char *s, int (*delim_comparator)(char*))
{
	str->current = s;
	str->after_protecting = skip_protected(str->current);
	str->delim_comparator = delim_comparator;
}

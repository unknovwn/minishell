#include "split_str.h"

size_t		copy_strings(t_arr_strings *strings, t_split_str s)
{
	size_t	i;

	i = 0;
	while (i < strings->len)
	{
		skip_sep(&s);
		strings->arr[i] = copy_and_skip_string(&s);
		if (strings->arr[i] == NULL)
			break ;
		i += 1;
	}
	return (i);
}

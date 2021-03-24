#include "split_str.h"

size_t		count_strings(t_split_str s)
{
	size_t		word_count;

	word_count = 0;
	while (*s.current != '\0')
	{
		if (!(is_sep(&s)))
		{
			word_count += 1;
			skip_string(&s);
		}
		else
			skip_sep(&s);
	}
	return (word_count);
}

#include "split_str.h"

static char	*copy_with_and_skip_symbol(char *dst, t_split_str *s)
{
	*dst = *s->current;
	dst += 1;
	s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

static char	*copy_with_and_skip_protected(char *dst, t_split_str *s)
{
	if (*s->current == '\\')
		dst = copy_with_and_skip_bslash_protecting(dst, s);
	else
		dst = copy_with_and_skip_quotes_protecting(dst, s);
	return (dst);
}

static void	copy_with_string(char *dst, t_split_str s)
{
	char	*dst_begin;

	dst_begin = dst;
	while (!(is_end_or_sep(&s)))
	{
		if (is_protect(*s.current))
			dst = copy_with_and_skip_protected(dst, &s);
		else
			dst = copy_with_and_skip_symbol(dst, &s);
	}
	*dst = '\0';
}

char		*copy_and_skip_string_with_protect(t_split_str *s)
{
	char	*string;
	size_t	string_len;

	string_len = count_string_len_with_protect(*s);
	string = (char*)malloc(sizeof(char) * (string_len + 1));
	if (string == NULL)
		return (NULL);
	string[string_len] = '\0';
	copy_with_string(string, *s);
	skip_string(s);
	return (string);
}

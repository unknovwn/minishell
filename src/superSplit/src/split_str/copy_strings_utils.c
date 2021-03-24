#include "split_str.h"

char	*copy_and_skip_bslash_protecting(char *dst, t_split_str *s)
{
	s->current += 1;
	*dst = *s->current;
	dst += 1;
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char	*copy_and_skip_quotes_protecting(char *dst, t_split_str *s)
{
	s->current += 1;
	while (s->current != s->after_protecting - 1)
	{
		*dst = *s->current;
		dst += 1;
		s->current += 1;
	}
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char	*copy_with_and_skip_bslash_protecting(char *dst, t_split_str *s)
{
	*dst = *s->current;
	s->current += 1;
	dst += 1;
	*dst = *s->current;
	dst += 1;
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char	*copy_with_and_skip_quotes_protecting(char *dst, t_split_str *s)
{
	while (s->current != s->after_protecting)
	{
		*dst = *s->current;
		dst += 1;
		s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

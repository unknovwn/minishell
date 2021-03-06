#include "split_str.h"

int		is_protect(char c)
{
	return (c == '\'' || c == '\"' || c == '\\');
}

char	*skip_symbols(const char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		if (*s == '\\')
			s = (const char*)sup_skip_bslash((char*)s);
		else
			s += 1;
	}
	if (*s == '\0')
		return ((char*)s);
	else
		return ((char*)(s + 1));
}

char	*skip_protected(const char *s)
{
	if (s == NULL)
		return (NULL);
	else if (*s == '\'')
		s = skip_symbols(s + 1, '\'');
	else if (*s == '\"')
		s = skip_symbols(s + 1, '\"');
	else if (*s == '\\' && *(s + 1) != '\0')
		s += 2;
	else if (*s == '\\' && *(s + 1) == '\0')
		s += 1;
	return ((char*)s);
}

int		is_end_or_sep(t_split_str *s)
{
	return (*s->current == '\0' || is_sep(s));
}

void	skip_string(t_split_str *s)
{
	while (!(is_end_or_sep(s)))
	{
		if (s->current != s->after_protecting)
			s->current = s->after_protecting;
		else
			s->current += 1;
		s->after_protecting = skip_protected(s->current);
	}
	s->after_protecting = skip_protected(s->current);
}

#include "libft.h"

char	*skip_space(char *current)
{
	while (ft_isspace(*current) && *current != '\0')
		current += 1;
	return (current);
}

char	*skip_bslash(char *current)
{
	if (*(current + 1) != '\0')
		return (current + 2);
	else
		return (current + 1);
}

char	*cse_skip_symbols(char *current, char c)
{
	while (*current != c)
	{
		if (*current == '\\')
			current = skip_bslash(current);
		else
			current += 1;
	}
	if (*current == c)
		return (current + 1);
	else
		return (current);
}

int		cse_is_protect(char c)
{
	return (c == '\'' || c == '\"' || c == '\\');
}

char	*cse_skip_protected(char *current)
{
	if (*current == '\\')
		current = skip_bslash(current);
	else if (*current == '\'')
		current = cse_skip_symbols(current + 1, '\'');
	else if (*current == '\"')
		current = cse_skip_symbols(current + 1, '\"');
	if (cse_is_protect(*current))
		current = cse_skip_protected(current);
	return (current);
}

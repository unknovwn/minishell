#include <stdbool.h>

#include "libft.h"

int	is_redirect_from(char *s)
{
	return (*s == '<');
}

int	is_redirect_to(char *s)
{
	if (*s == '\0')
		return (0);
	else if (*s == '>' && *(s + 1) != '>' && *(s - 1) != '>')
		return (1);
	else
		return (0);
}

int	is_redirect_double_to(char *s)
{
	if (ft_memcmp(s, ">>", 2) == 0)
		return (2);
	else
		return (0);
}

int	is_redirect_or_space(char *s)
{
	if (*s == '<' || *s == '>')
		return (1);
	else if (ft_isspace(*s))
		return (1);
	else
		return (0);
}

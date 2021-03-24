#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;
	char *copy_begin;

	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (0);
	copy_begin = copy;
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (copy_begin);
}

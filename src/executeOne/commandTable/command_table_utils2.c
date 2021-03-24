#include <stdlib.h>

size_t	count_strs(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs != NULL)
	{
		len += 1;
		strs += 1;
	}
	return (len);
}

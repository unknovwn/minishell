#include "stdlib.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (len--)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

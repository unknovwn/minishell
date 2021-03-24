#include "libft.h"

size_t	get_number_len(unsigned int n)
{
	size_t len;

	len = !n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	size_t	result_len;

	result_len = get_number_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	result[result_len] = '\0';
	while (result_len)
	{
		result[--result_len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

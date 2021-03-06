/*
**	Function works like atoi (man atoi),
**	but the number is based on a give
**	number system.
*/

#include <stdio.h>
#include "ft_fprintf.h"

static size_t	take_nb_len(long long nb, size_t len_base)
{
	size_t	len;

	if (len_base == 0)
		return (0);
	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		nb /= len_base;
		len++;
	}
	return (len);
}

char			*ft_prf_uitoa_base(uint64_t nb, char *base)
{
	char	*res;
	size_t	nb_len;
	size_t	base_len;

	if (base == NULL)
		return (NULL);
	base_len = ft_prf_strlen(base);
	nb_len = take_nb_len(nb, base_len);
	if ((res = (char*)malloc(sizeof(char) * (nb_len + 1))) == NULL)
		return (NULL);
	res[nb_len] = '\0';
	while (nb_len--)
	{
		res[nb_len] = base[nb % base_len];
		nb /= base_len;
	}
	return (res);
}

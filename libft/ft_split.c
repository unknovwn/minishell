/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:14:35 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/12/27 19:08:28 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_lentodelim(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static unsigned int	count_substr(char const *s, char c)
{
	unsigned int	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
			s--;
		}
		s++;
	}
	return (counter);
}

static char			*ft_substrcpy(char const *s, size_t len)
{
	char *result;
	char *result_start;

	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result_start = result;
	while (len--)
		*result++ = *s++;
	*result = '\0';
	return (result_start);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	substr_count;
	char			**result;
	int				i;
	size_t			substr_len;

	if (!s)
		return (0);
	substr_count = count_substr(s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (substr_count + 1))))
		return (0);
	result[substr_count] = 0;
	i = 0;
	while (substr_count--)
	{
		while (*s == c)
			s++;
		substr_len = ft_lentodelim(s, c);
		if (!(result[i++] = ft_substrcpy(s, substr_len)))
		{
			free_string_arr(result);
			return (0);
		}
		s += substr_len;
	}
	return (result);
}

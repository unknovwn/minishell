/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:22:57 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/11 18:35:18 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_chars(char *str, int (*char_comparator)(int))
{
	size_t	result_len;
	char	*str_start;
	char	*result;
	char	*result_start;

	result_len = 0;
	str_start = str;
	while (*str_start)
	{
		if (!(char_comparator(*str_start++)))
			result_len++;
	}
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	result_start = result;
	while (*str)
	{
		if (!(char_comparator(*str)))
			*result++ = *str;
		str++;
	}
	*result = '\0';
	return (result_start);
}

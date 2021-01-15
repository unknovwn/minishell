/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:24:48 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 23:05:42 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, int dstsize)
{
	size_t	src_strlen;

	if (dstsize < 0)
		dstsize = 0;
	if (!dst || !src)
		return (0);
	src_strlen = ft_strlen(src);
	if (dstsize == 0)
		return (src_strlen);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_strlen);
}

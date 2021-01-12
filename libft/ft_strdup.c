/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:10:44 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/10/30 20:51:13 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

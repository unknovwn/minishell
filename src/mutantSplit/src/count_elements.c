/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_result_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:24:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:24:23 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdbool.h>
#include "mutant_split.h"

char		*skip_symbols(const char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == '\0')
		return ((char*)s);
	else
		return ((char*)(s + 1));
}

int			is_protect(char c)
{
	return (c == '\'' || c == '\"' || c == '\\');
}

char		*skip_protected(const char *s)
{
	if (*s == '\0')
		return ((char*)s);
	if (*s == '\'')
		s = skip_symbols(s + 1, '\'');
	else if (*s == '\"')
		s = skip_symbols(s + 1, '\"');
	else if (*s == '\\' && *(s + 1) != '\0')
		s += 2;
	else if (*s == '\\' && *(s + 1) == '\0')
		s += 1;
	if (is_protect(*s) == true)
		s = (const char*)skip_protected(s);
	return ((char*)s);
}

size_t		count_elements(const char *s, char c)
{
	char	*after_protecting;
	size_t	len;
	uint8_t	new_word_flag;

	if (s == NULL)
		return (0);
	len = 0;
	new_word_flag = 1;
	while (*s != '\0')
	{
		after_protecting = skip_protected(s);
		if (s != after_protecting && new_word_flag == true)
		{
			new_word_flag = false;
			len++;
		}
		s = after_protecting;
		if (*s != c && new_word_flag == true)
		{
			new_word_flag = false;
			len++;
		}
		if (*s == c)
			new_word_flag = true;
		if (*s == '\0')
			break ;
		s += 1;
	}
	return (len);
}


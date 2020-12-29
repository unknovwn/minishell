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
#include "split_commands.h"

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

static int	next_is_new_command(const char *s, char c, uint8_t word_flag)
{
	return (*s == c && *(s + 1) != '\0' && word_flag == true);
}

size_t		count_commands(const char *s, char c)
{
	size_t	len;
	uint8_t	word_flag;

	if (s == NULL)
			return (0);
	len = 1;
	word_flag = 1;
	while (*s != '\0')
	{
		s = (const char*)skip_protected(s);
		if (*s != c)
			word_flag = true;
		if (next_is_new_command(s, c, word_flag) == true)
		{
			word_flag = false;
			len += 1;
		}
		s++;
	}
	return (len);
}


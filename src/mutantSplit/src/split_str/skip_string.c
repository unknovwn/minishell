/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:47:08 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 05:27:37 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "mutant_split.h"
#include "split_str.h"

int		is_protect(char c)
{
	return (c == '\'' || c == '\"' || c == '\\');
}

char	*skip_symbols(const char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == '\0')
		return ((char*)s);
	else
		return ((char*)(s + 1));
}

char	*skip_protected(const char *s)
{
	if (s == NULL)
		return (NULL);
	else if (*s == '\'')
		s = skip_symbols(s + 1, '\'');
	else if (*s == '\"')
		s = skip_symbols(s + 1, '\"');
	else if (*s == '\\' && *(s + 1) != '\0')
		s += 2;
	else if (*s == '\\' && *(s + 1) == '\0')
		s += 1;
	return ((char*)s);
}

int		is_end_or_sep(t_split_str *s)
{
	return (*s->current == '\0' ||
			*s->current == s->separator);
}

void	skip_string(t_split_str *s)
{
	while (is_end_or_sep(s) == false)
	{
		if (s->current != s->after_protecting)
			s->current = s->after_protecting;
		else
			s->current += 1;
		s->after_protecting = skip_protected(s->current);
	}
	s->after_protecting = skip_protected(s->current);
}

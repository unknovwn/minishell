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
#include <unistd.h>

#include <stdbool.h>
#include "mutant_split.h"

static char	*skip_symbols(const char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == '\0')
		return ((char*)s);
	else
		return ((char*)(s + 1));
}

static int	is_protect(char c)
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

static void	skip_word(t_split_str *s)
{
	if (is_protect(*(s->current)))
		s->current = skip_protected(s->current);
	else
		s->current += 1;
}

int			is_end_or_sep(t_split_str *s)
{
	return (*s->current != '\0' &&
			*s->current != s->separator);
}

static void	count_and_skip_word(size_t *word_count, t_split_str *s)
{
	*word_count += 1;
	s->new_word_flag = 0;
	s->current = s->after_protecting;
	while (is_end_or_sep(s))
		skip_word(s);
	s->after_protecting = skip_protected(s->current);
}

int			is_new_word(t_split_str *s)
{
	return (*s->current != s->separator &&
			s->new_word_flag == true);
}

static void	count(size_t *word_count, t_split_str *s)
{
	if (is_new_word(s) == true)
		count_and_skip_word(word_count, s);
	if (*(s->current) == s->separator)
		s->new_word_flag = true;
	if (is_protect(*s->current))
		s->current = skip_protected(s->current);
	else if (*(s->current) != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
}

size_t		count_elements(t_split_str s)
{
	size_t		word_count;

	word_count = 0;
	while (*(s.current) != '\0')
		count(&word_count, &s);
	return (word_count);
}


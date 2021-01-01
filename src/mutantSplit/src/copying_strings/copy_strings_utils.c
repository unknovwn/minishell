/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strings_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:21:39 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 01:21:40 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mutant_split.h"

void	skip_string(t_split_str *s)
{
	while (is_end_or_sep(s) == false)
	{
		if (s->current != s->after_protecting)
			s->current = s->after_protecting;
		else if (is_end_or_sep(s) == false)
			s->current += 1;
		s->after_protecting = skip_protected(s->current);
	}
	s->after_protecting = skip_protected(s->current);
}

void	skip_sep(t_split_str *s)
{
	while (*s->current == s->separator && *s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
}

char	*copy_and_skip_backslash_protecting(char *dst, t_split_str *s)
{
	s->current += 1;
	*dst = *s->current;
	dst += 1;
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char	*copy_and_skip_quotes_protecting(char *dst, t_split_str *s)
{
	s->current += 1;
	while (s->current != s->after_protecting - 1)
	{
		*dst = *s->current;
		dst += 1;
		s->current += 1;
	}
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}


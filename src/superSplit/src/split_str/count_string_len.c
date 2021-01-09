/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_string_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 03:15:48 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 03:15:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "split_str.h"

static size_t	count_and_skip_protected(t_split_str *s)
{
	size_t	len;

	len = s->after_protecting - s->current;
	if (*s->current == '\'' || *s->current == '\"')
		len -= 2;
	else if (*s->current == '\\')
		len -= 1;
	s->current = s->after_protecting;
	s->after_protecting = skip_protected(s->current);
	return (len);
}

static size_t	count_and_skip_symbol(t_split_str *s)
{
	s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (1);
}

size_t			count_string_len(t_split_str s)
{
	size_t	len;

	len = 0;
	while (is_end_or_sep(&s) == false)
	{
		if (is_protect(*s.current))
			len += count_and_skip_protected(&s);
		else if (is_end_or_sep(&s) == false)
			len += count_and_skip_symbol(&s);
	}
	return (len);
}

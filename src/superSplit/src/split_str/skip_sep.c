/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:52:35 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 21:35:03 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"

char		*sup_skip_bslash(char *s)
{
	if (*(s + 1) != '\0')
		s += 2;
	else
		s += 1;
	return (s);
}

int			is_sep(t_split_str *s)
{
	return (s->delim_comparator(s->current));
}

static int	is_sep_and_is_not_end(t_split_str *s)
{
	return (is_sep(s) && *s->current != '\0');
}

void		skip_sep(t_split_str *s)
{
	while (is_sep_and_is_not_end(s))
	{
		s->current += s->delim_comparator(s->current);
	}
	s->after_protecting = skip_protected(s->current);
}

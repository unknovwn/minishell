/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strings_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:21:39 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 21:35:18 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"

char	*copy_and_skip_bslash_protecting(char *dst, t_split_str *s)
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

char	*copy_with_and_skip_bslash_protecting(char *dst, t_split_str *s)
{
	*dst = *s->current;
	s->current += 1;
	dst += 1;
	*dst = *s->current;
	dst += 1;
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char	*copy_with_and_skip_quotes_protecting(char *dst, t_split_str *s)
{
	while (s->current != s->after_protecting)
	{
		*dst = *s->current;
		dst += 1;
		s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
	return (dst);
}
